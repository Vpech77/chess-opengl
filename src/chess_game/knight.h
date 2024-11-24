#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    private:
        std::string m_color;
        std::string m_typ;
        glm::vec2 m_coord;

    public:
        Knight(std::string color, glm::vec2 coord);


};

#endif
