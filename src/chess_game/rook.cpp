#include "rook.h"

Rook::Rook(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_ROOK);
    }
    else{
        this->setType(TypePiece::BLACK_ROOK);
    }
}

