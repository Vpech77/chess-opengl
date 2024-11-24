#include "pawn.h"

Pawn::Pawn(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_PAWN);
    }
    else{
        this->setType(TypePiece::BLACK_PAWN);
    }
}

