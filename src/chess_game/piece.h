#ifndef PIECE_H
#define PIECE_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <string>

#include "typePiece.h"

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
        void setType(TypePiece typ);


};

#endif
