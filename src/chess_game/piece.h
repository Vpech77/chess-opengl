#ifndef PIECE_H
#define PIECE_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <string>
#include <vector>

#include "typePiece.h"

class Plato;

class Piece
{
    private:
        std::string m_color;
        TypePiece m_typ;
        glm::vec2 m_coord;


    public:
        Piece(std::string color, glm::vec2 coord);
        virtual ~Piece();
        TypePiece getType();
        std::string getColor();
        void setType(TypePiece typ);
        virtual std::vector<glm::vec2> movePossible(Piece* (&array)[8][8]) = 0;
        void move(glm::vec2& newCoord, Plato& board);
        glm::vec2 getCoord();

};

#endif
