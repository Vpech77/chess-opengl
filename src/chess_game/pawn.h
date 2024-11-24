#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    private:
        std::string m_color;
        std::string m_typ;
        glm::vec2 m_coord;

    public:
        Pawn(std::string color, glm::vec2 coord);


};

#endif
