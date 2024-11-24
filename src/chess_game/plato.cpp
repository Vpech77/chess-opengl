#include "plato.h"
#include <filesystem>
#include <iostream>
#include <object.h>

#include "headerPieces.h"

Plato::Plato(): caseBlack(nullptr), caseWhite(nullptr), p()
{
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
    std::string pathOBJ = path + "/model/case.obj";

    caseBlack = new Object(pathOBJ.c_str(), path + "/textures/caseNoire.png");
    caseWhite = new Object(pathOBJ.c_str(), path + "/textures/caseBlanche.png");

    p.push_back(createPiece3D("white", "pawn"));
    p.push_back(createPiece3D("black", "pawn"));


    initArray();
}

void Plato::initArray(){
    for (int col = 0; col < 8; ++col){
        for (int li = 0; li < 8; ++li){
            glm::vec2 pos(col, li);
            if (li == 1){
                array[col][li] = new Pawn("white", pos);
            }
            else if (li == 6){
                array[col][li] = new Pawn("black", pos);
            }
            else{
                array[col][li] = nullptr;
            }
        }
    }
}



Object* Plato::createPiece3D(std::string color, std::string typ){
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
    std::string pathOBJ = path + "/model/"+ typ +".obj";

    return new Object(pathOBJ.c_str(), path + "/textures/"+color+".png");
}


Plato::~Plato()
{
    delete caseBlack;
    delete caseWhite;
    for (Object* piece : p){
        delete piece; 
    }
    p.clear();

    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            delete array[i][j];
        }
    }
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

    // for (int i = 0; i < 8; i++) {
    //     glm::vec3 posPawnWhite(i*tailleCase, 2, 0);
    //     renderCase(va, cam, shader, renderer, *p.at(0), posPawnWhite);
    //     glm::vec3 posPawnBlack(i*tailleCase, 6*tailleCase, 0);
    //     renderCase(va, cam, shader, renderer, *p.at(1), posPawnBlack);
    // }

    for (int i=0; i<nbCase; i++){
        for (int j=0; j<nbCase; j++){
            if(array[i][j]){
                glm::vec3 pos(i*tailleCase, j*tailleCase, 0);
                renderCase(va, cam, shader, renderer, *p.at(array[i][j]->getType()), pos);
            }
        }
    }


    for (int i=0; i<nbCase; i++){
        if (i%2==0){
            for (int j=0; j<nbCase; j++){
                glm::vec3 pos(i*tailleCase, j*tailleCase, 0);
                if (j%2==0){
                    renderCase(va, cam, shader, renderer, *caseBlack, pos);
                    std::cout<<" N : ("<<i*tailleCase<<","<<j*tailleCase<<")";
                }
                else{
                    renderCase(va, cam, shader, renderer, *caseWhite, pos);
                    std::cout<<" B : ("<<i*tailleCase<<","<<j*tailleCase<<")";
                }
            }
            std::cout<<"\n";
        }
        else{
            for (int j=0; j<nbCase; j++){
                glm::vec3 pos(i*tailleCase, j*tailleCase, 0);
                if (j%2==0){
                    renderCase(va, cam, shader, renderer, *caseWhite, pos);
                    std::cout<<" B : ("<<i*tailleCase<<","<<j*tailleCase<<")";
                }
                else{
                    renderCase(va, cam, shader, renderer, *caseBlack, pos);
                    std::cout<<" N : ("<<i*tailleCase<<","<<j*tailleCase<<")";
                }
            }
            std::cout<<"\n";
        }
    }
    std::cout<<"------------------------------\n";
}