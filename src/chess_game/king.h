#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    private:
        std::string m_color;
        std::string m_typ;
        glm::vec2 m_coord;

    public:
        King(std::string color, glm::vec2 coord);


};

#endif
