#include "object.h"

#include <filesystem>
#include <iostream>
#include "renderer.h"
#include "glm/gtx/transform.hpp"

#include <exception>
#include <string.h>


Object::Object(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::string texturePath):m_vb(0), m_uvsb(0), m_texture(0), position(0,0,0), rotationAngles(0,0,0)
{
     m_vb = new VertexBuffer(vertices);
     m_uvsb = new UVBuffer(uvs);

     m_texture = new Texture(texturePath);
}

Object::Object(const char* objPath, std::string texturePath):m_vb(0), m_uvsb(0), m_texture(0), position(0,0,0), rotationAngles(0,0,0)
{
    std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	bool resCase = loadOBJ(objPath, vertices, uvs);
    if(resCase) {
        std::cout << "Fichier OBJ chargé avec succès. Vertices : " << vertices.size() << ", UVs : " << uvs.size() << std::endl;
        
        try {
            m_vb = new VertexBuffer(vertices);
            m_uvsb = new UVBuffer(uvs);
            m_texture = new Texture(texturePath);
            
            std::cout << "Objet créé avec succès." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de la création des buffers ou de la texture : " << e.what() << std::endl;
            throw;
        }
    } else {
        std::cerr << "Impossible de charger le fichier OBJ : " << objPath << std::endl;
        throw std::runtime_error("Échec du chargement du fichier OBJ");
    	}
}


Object::~Object()
{
    delete m_vb;
    if (m_uvsb) delete m_uvsb;
    if (m_texture) delete m_texture;
}

void Object::Bind() const
{
    m_vb->Bind(0);
    if (m_uvsb) m_uvsb->Bind(1);
    if (m_texture) m_texture->Bind(0);
}

void Object::Unbind() const
{
    m_vb->Unbind();
    if (m_uvsb) m_uvsb->Unbind();
    if (m_texture) m_texture->Unbind();
}

void Object::setRotation(glm::vec3 rot){
	rotationAngles = rot;
}

void Object::Draw() const
{
    GLCall(glDrawArrays(GL_TRIANGLES,0, m_vb->getSize()));
}

glm::mat4 Object::getModelMatrix()
{
    glm::mat4 m = glm::rotate(glm::translate(glm::mat4(1), position), rotationAngles.x, glm::vec3(1,0,0));
    m=glm::rotate(m, rotationAngles.y, glm::vec3(0,1,0));
    m=glm::rotate(m, rotationAngles.z, glm::vec3(0,0,1));
    return m;
}

bool Object::loadOBJ(const char * objPath, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_uvs){
	printf("Loading OBJ file %s...\n", objPath);

	std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices; 
	std::vector<glm::vec2> temp_uvs;


	FILE * file = fopen(objPath, "r");
	if( file == NULL ){
		printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
		getchar();
		return false;
	}

	while( 1 ){

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.

		// else : parse lineHeader
		
		if ( strcmp( lineHeader, "v" ) == 0 ){
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}else if ( strcmp( lineHeader, "vt" ) == 0 ){
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y );
			temp_uvs.push_back(uv);
		}else if ( strcmp( lineHeader, "f" ) == 0 ){
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			if (matches != 9){
				printf("File can't be read by our simple parser :-( Try exporting with other options\n");
				fclose(file);
				return false;
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices    .push_back(uvIndex[0]);
			uvIndices    .push_back(uvIndex[1]);
			uvIndices    .push_back(uvIndex[2]);
		}else{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}

	}

	// For each vertex of each triangle
	for( unsigned int i=0; i<vertexIndices.size(); i++ ){

		// Get the indices of its attributes
		unsigned int vertexIndex = vertexIndices[i];
		unsigned int uvIndex = uvIndices[i];
		
		// Get the attributes thanks to the index
		glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
		glm::vec2 uv = temp_uvs[ uvIndex-1 ];
		
		// Put the attributes in buffers
		out_vertices.push_back(vertex);
		out_uvs     .push_back(uv);
	
	}
	fclose(file);
	return true;
}