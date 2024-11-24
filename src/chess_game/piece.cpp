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

glm::vec2 Piece::getCoord(){
    return m_coord;
}

std::string Piece::getColor(){
    return m_color;
}

void Piece::move(glm::vec2& newCoord){
    m_coord = newCoord;
}