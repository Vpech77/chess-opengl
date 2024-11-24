#include "bishop.h"

Bishop::Bishop(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_BISHOP);
    }
    else{
        this->setType(TypePiece::BLACK_BISHOP);
    }

}

