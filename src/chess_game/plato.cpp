#include "plato.h"
#include <filesystem>
#include <iostream>
#include "loadModel.h"


Plato::Plato(): caseBlack(nullptr), caseWhite(nullptr)
{
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
	std::vector<glm::vec3> normalsCase; // Won't be used at the moment.
	bool resCase = loadOBJ("/home/vpech/Documents/Github/Chess-OpenGL/src/model/case.obj", verticesCase, uvsCase, normalsCase);

    if(resCase){
        caseBlack = new Object(verticesCase, uvsCase, path + "/textures/caseNoire.png");
        caseWhite = new Object(verticesCase, uvsCase, path + "/textures/caseBlanche.png");
    }
    else{
        throw std::runtime_error("Impossible de charger le fichier OBJ de la case");
    }
}

Plato::~Plato()
{
    delete caseBlack;
    delete caseWhite;
}

glm::mat4 mvpObject(glm::vec3 pos, Object& o, Camera& cam)
{
    o.position = pos;
    glm::mat4 m = o.getModelMatrix();
    glm::mat4 v = cam.getViewMatrix();
    glm::mat4 p = cam.getProjectionMatrix();
    glm::mat4 mvp = p*v*m;

    return mvp;
}


void Plato::Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer) 
{
        int nbCase = 8;
        int tailleCase = 2;
        glm::mat4 mvp;

        for (int i=0; i<nbCase; i++){
            if (i%2==0){
                for (int j=0; j<nbCase; j++){
                    glm::vec3 pos(i*2, j*2, 0);
                    if (j%2==0){
                        
                        mvp = mvpObject(pos, *caseBlack, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, *caseBlack, shader);
                    }
                    else{
                        mvp = mvpObject(pos, *caseWhite, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, *caseWhite, shader);
                    }
                }
            }
            else{
                for (int j=0; j<nbCase; j++){
                    glm::vec3 pos(i*2, j*2, 0);
                    if (j%2==0){
                        mvp = mvpObject(pos, *caseWhite, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, *caseWhite, shader);
                    }
                    else{
                        mvp = mvpObject(pos, *caseBlack, cam);
                        shader.setUniformMat4f("MVP", mvp);
                        renderer.Draw(va, *caseBlack, shader);
                    }
                }
            }
        }
}