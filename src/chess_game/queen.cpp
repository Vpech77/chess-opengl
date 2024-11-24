#include "queen.h"

Queen::Queen(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_QUEEN);
    }
    else{
        this->setType(TypePiece::BLACK_QUEEN);
    }
}

