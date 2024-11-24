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
    p.push_back(createPiece3D("white", "rook"));
    p.push_back(createPiece3D("black", "rook"));
    p.push_back(createPiece3D("white", "knight"));
    p.push_back(createPiece3D("black", "knight"));
    p.push_back(createPiece3D("white", "bishop"));
    p.push_back(createPiece3D("black", "bishop"));
    p.push_back(createPiece3D("white", "king"));
    p.push_back(createPiece3D("black", "king"));
    p.push_back(createPiece3D("white", "queen"));
    p.push_back(createPiece3D("black", "queen"));

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

    int liWhite = 0;
    array[0][liWhite] = new Rook  ("white", glm::vec2(0, liWhite));
    array[1][liWhite] = new Knight("white", glm::vec2(1, liWhite));
    array[2][liWhite] = new Bishop("white", glm::vec2(2, liWhite));
    array[3][liWhite] = new Queen ("white", glm::vec2(3, liWhite));
    array[4][liWhite] = new King  ("white", glm::vec2(4, liWhite));
    array[5][liWhite] = new Bishop("white", glm::vec2(5, liWhite));
    array[6][liWhite] = new Knight("white", glm::vec2(6, liWhite));
    array[7][liWhite] = new Rook  ("white", glm::vec2(7, liWhite));

    int liBlack = 7;
    array[0][liBlack] = new Rook  ("black", glm::vec2(0, liBlack));
    array[1][liBlack] = new Knight("black", glm::vec2(1, liBlack));
    array[2][liBlack] = new Bishop("black", glm::vec2(2, liBlack));
    array[3][liBlack] = new King  ("black", glm::vec2(3, liBlack));
    array[4][liBlack] = new Queen ("black", glm::vec2(4, liBlack));
    array[5][liBlack] = new Bishop("black", glm::vec2(5, liBlack));
    array[6][liBlack] = new Knight("black", glm::vec2(6, liBlack));
    array[7][liBlack] = new Rook  ("black", glm::vec2(7, liBlack));
    

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
                }
                else{
                    renderCase(va, cam, shader, renderer, *caseWhite, pos);
                }
            }
            std::cout<<"\n";
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