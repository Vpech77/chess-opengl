#include "knight.h"
#include <iostream>

Knight::Knight(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_KNIGHT);
    }
    else{
        this->setType(TypePiece::BLACK_KNIGHT);
    }
}

std::vector<glm::vec2> Knight::movePossible(Piece* (&array)[8][8]){
    std::vector<glm::vec2> moves;
    int col = this->getCoord().x;
    int li = this->getCoord().y;

    std::vector<glm::vec2> lst = {
        glm::vec2(col-1, li-2),
        glm::vec2(col+1, li-2),
        glm::vec2(col+2, li-1),
        glm::vec2(col+2, li+1),
        glm::vec2(col+1, li+2),
        glm::vec2(col-1, li+2),
        glm::vec2(col-2, li+1),
        glm::vec2(col-2, li-1)
    };

    for (const auto& move : lst){
        if (move.x >= 0 && move.x <= 7 && move.y >= 0 && move.y <= 7){
            if (!array[static_cast<int>(move.x)][static_cast<int>(move.y)]){
                moves.push_back(move);
            }
            else if (array[static_cast<int>(move.x)][static_cast<int>(move.y)]->getColor() != array[col][li]->getColor()){
                moves.push_back(move);
            }
        }
    }


    for (const auto& v : moves) { 
        std::cout << "(" << v.x << ", " << v.y << ")" << std::endl; 
    }
    return moves;
}
