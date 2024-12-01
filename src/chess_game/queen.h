#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{

    public:
        Queen(std::string color, glm::vec2 coord);
        std::vector<glm::vec2> movePossible(Piece* (&array)[8][8]) override;

};

#endif
