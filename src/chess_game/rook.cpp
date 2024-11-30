#include "rook.h"
#include <iostream>

Rook::Rook(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_ROOK);
    }
    else{
        this->setType(TypePiece::BLACK_ROOK);
    }
}

std::vector<glm::vec2> Rook::movePossible(Piece* (&array)[8][8]){
    std::vector<glm::vec2> lst;
    int col = this->getCoord().x;
    int li = this->getCoord().y;

    // hori droite
    for (int i=col+1; i<8; ++i){
        if (i != col){
            if (!array[i][li]){ // case vide
                lst.push_back(glm::vec2(i, li));
            }
            else{
                if (array[i][li]->getColor() != array[col][li]->getColor()){
                    lst.push_back(glm::vec2(i, li));
                }
                break;
            }
        }
    }

    // hori gauche
    for (int i=col-1; 0<=i; --i){
        if (i != col){
            if (!array[i][li]){ // case vide
                lst.push_back(glm::vec2(i, li));
            }
            else{
                if (array[i][li]->getColor() != array[col][li]->getColor()){
                    lst.push_back(glm::vec2(i, li));
                }
                break;
            }
        }
    }

    // verti haut
    for (int i=li+1; i<8; ++i){
        if (i != li){
            if (!array[col][i]){ // case vide
                lst.push_back(glm::vec2(col, i));
            }
            else{
                if (array[col][i]->getColor() != array[col][li]->getColor()){
                    lst.push_back(glm::vec2(col, i));
                }
                break;
            }
        }
    }

    // verti bas
    for (int i=li-1; 0<=i; --i){
        if (i != li){
            if (!array[col][i]){ // case vide
                lst.push_back(glm::vec2(col, i));
            }
            else{
                if (array[col][i]->getColor() != array[col][li]->getColor()){
                    lst.push_back(glm::vec2(col, i));
                }
                break;
            }
        }
    }


    for (const auto& v : lst) { 
        std::cout << "(" << v.x << ", " << v.y << ")" << std::endl; 
    }
    return lst;
}
