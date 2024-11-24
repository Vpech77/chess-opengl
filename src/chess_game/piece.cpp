#include "piece.h"

Piece::Piece(std::string color, glm::vec2 coord)
    :m_color(color), m_coord(coord), m_typ(TypePiece::WHITE_PAWN)
{

}

Piece::~Piece(){}

TypePiece Piece::getType(){
    return m_typ;
}

void Piece::setType(TypePiece typ){
    m_typ = typ;
}