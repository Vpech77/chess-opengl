#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
    private:
        std::string m_color;
        std::string m_typ;
        glm::vec2 m_coord;

    public:
        Bishop(std::string color, glm::vec2 coord);


};

#endif
