#include "plato.h"
#include <filesystem>
#include <iostream>
#include <object.h>
#include "loadModel.h"


Plato::Plato(): caseBlack(nullptr), caseWhite(nullptr)
{
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
    std::string pathOBJ = path + "/model/case.obj";

    caseBlack = new Object(pathOBJ.c_str(), path + "/textures/caseNoire.png");
    caseWhite = new Object(pathOBJ.c_str(), path + "/textures/caseBlanche.png");

}

Plato::~Plato()
{
    delete caseBlack;
    delete caseWhite;
}

void Plato::renderCase(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer, Object& o, glm::vec3& pos){
    o.position = pos;
    glm::mat4 m = o.getModelMatrix();
    glm::mat4 v = cam.getViewMatrix();
    glm::mat4 p = cam.getProjectionMatrix();
    glm::mat4 mvp = p*v*m;
    shader.setUniformMat4f("MVP", mvp);
    renderer.Draw(va, o, shader);
}

void Plato::Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer) 
{
        int nbCase = 8;
        int tailleCase = 2;

        for (int i=0; i<nbCase; i++){
            if (i%2==0){
                for (int j=0; j<nbCase; j++){
                    glm::vec3 pos(i*tailleCase, j*tailleCase, 0);
                    if (j%2==0){
                        renderCase(va, cam, shader, renderer, *caseBlack, pos);
                    }
                    else{
                        renderCase(va, cam, shader, renderer, *caseWhite, pos);
                    }
                }
            }
            else{
                for (int j=0; j<nbCase; j++){
                    glm::vec3 pos(i*tailleCase, j*tailleCase, 0);
                    if (j%2==0){
                        renderCase(va, cam, shader, renderer, *caseWhite, pos);
                    }
                    else{
                        renderCase(va, cam, shader, renderer, *caseBlack, pos);
                    }
                }
            }
        }
}