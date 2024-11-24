#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    private:
        std::string m_color;
        std::string m_typ;
        glm::vec2 m_coord;

    public:
        Rook(std::string color, glm::vec2 coord);


};

#endif
