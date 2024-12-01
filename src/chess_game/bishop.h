#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
    public:
        Bishop(std::string color, glm::vec2 coord);
        std::vector<glm::vec2> movePossible(Piece* (&array)[8][8]) override;

};

#endif
