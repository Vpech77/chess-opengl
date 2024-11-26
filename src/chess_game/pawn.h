#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    public:
        Pawn(std::string color, glm::vec2 coord);
        std::vector<glm::vec2> movePossible(Piece* (&array)[8][8]) override;


};

#endif
