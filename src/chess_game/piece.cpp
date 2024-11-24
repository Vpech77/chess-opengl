#include "piece.h"

Piece::Piece(std::string color, std::string typ, glm::vec2 coord)
    :m_color(color), m_typ(typ), m_coord(coord)
{

}

Piece::~Piece(){}
