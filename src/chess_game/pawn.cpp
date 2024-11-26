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
        if (y == 1){  // avance de deux
            lst.push_back(glm::vec2(x, 3));
        }
        if (y != 7 && !(array[x][y+1])){
            lst.push_back(glm::vec2(x, y+1));
        }
    }

    else {
        if (y == 6){  // avance de deux
            lst.push_back(glm::vec2(x, 4));
        }
        if (y != 0 && !(array[x][y-1])){
            lst.push_back(glm::vec2(x, y-1));
        }
    }

    for (const auto& v : lst) { 
        std::cout << "(" << v.x << ", " << v.y << ")" << std::endl; 
        }

    return lst;

}

