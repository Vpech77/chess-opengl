#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    public:
        Rook(std::string color, glm::vec2 coord);
        std::vector<glm::vec2> movePossible(Piece* (&array)[8][8]) override;
};

#endif
