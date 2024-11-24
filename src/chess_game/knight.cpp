#include "knight.h"

Knight::Knight(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_KNIGHT);
    }
    else{
        this->setType(TypePiece::BLACK_KNIGHT);
    }
}

