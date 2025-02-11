#include "pawn.h"
#include <iostream>

Pawn::Pawn(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_PAWN);
    }
    else{
        this->setType(TypePiece::BLACK_PAWN);
    }
}

std::vector<glm::vec2> Pawn::movePossible(Piece* (&array)[8][8]){
    std::vector<glm::vec2> lst;

    int x = this->getCoord().x;
    int y = this->getCoord().y;

    if (this->getColor() == "white"){
        if (y == 1 && !(array[x][2]) && !(array[x][3])){  // avance de deux
            lst.push_back(glm::vec2(x, 3));
        }
        if (y != 7){ // pas sur last line

            if (!(array[x][y+1])){ // avance de un
                lst.push_back(glm::vec2(x, y+1)); 
            }
            // miam miam
            if (x != 0 && array[x-1][y+1] && array[x-1][y+1]->getColor() == "black"){ 
                lst.push_back(glm::vec2(x-1, y+1));
            }
            if (x != 7 && array[x+1][y+1] && array[x+1][y+1]->getColor() == "black"){
                lst.push_back(glm::vec2(x+1, y+1));
            }
        }
    }

    else {
        if (y == 6 && !(array[x][5]) && !(array[x][4])){  // avance de deux
            lst.push_back(glm::vec2(x, 4));
        }
        if (y != 0){
            if (!(array[x][y-1])){ // avance de un
                lst.push_back(glm::vec2(x, y-1));
            }
            // miam
            if (x !=0 && array[x-1][y-1] && array[x-1][y-1]->getColor()=="white"){ 
                lst.push_back(glm::vec2(x-1, y-1));
            }
            if (x != 7 && array[x+1][y-1] && array[x+1][y-1]->getColor()=="white"){
                lst.push_back(glm::vec2(x+1, y-1));
            }
        }
    }

    return lst;

}

