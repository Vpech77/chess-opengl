#include "queen.h"
#include <iostream>
#include "bishop.h"
#include "rook.h"

Queen::Queen(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_QUEEN);
    }
    else{
        this->setType(TypePiece::BLACK_QUEEN);
    }
}

std::vector<glm::vec2> Queen::movePossible(Piece* (&array)[8][8]){

    Bishop bishop(this->getColor(), this->getCoord());
    Rook rook(this->getColor(), this->getCoord());

    std::vector<glm::vec2> moves = bishop.movePossible(array);
    std::vector<glm::vec2> moves_rook = rook.movePossible(array);

    moves.insert(moves.end(), moves_rook.begin(), moves_rook.end());

    return moves;
}
