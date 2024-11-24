#include "king.h"

King::King(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_KING);
    }
    else{
        this->setType(TypePiece::BLACK_KING);
    }
}

