#ifndef PIECE_H
#define PIECE_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <string>

enum TypePiece {
    PionBlanc = 0,
    PionNoir = 1,
    RoiBlanc = 2,
    RoiNoir = 3,
    ReineBlanc = 4,
    ReineNoir = 5
    };

class Piece
{
    private:
        std::string m_color;
        std::string m_typ;
        glm::vec2 m_coord;


    public:
        Piece(std::string color, std::string typ, glm::vec2 coord);
        virtual ~Piece();


};

#endif
