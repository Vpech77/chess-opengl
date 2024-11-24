#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
    public:
        Bishop(std::string color, glm::vec2 coord);

};

#endif
