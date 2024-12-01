#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        King(std::string color, glm::vec2 coord);
        std::vector<glm::vec2> movePossible(Piece* (&array)[8][8]) override;


};

#endif
