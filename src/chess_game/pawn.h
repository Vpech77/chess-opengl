#ifndef PAWN_H
#define PAWN_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <shader.h>
#include <vertexarray.h>
#include <camera.h>
#include <renderer.h>
#include <object.h>

#include "piece.h"


class Pawn : public Piece
{
    public:
        Pawn(std::string m_color);
        void move(int x, int y) override;
};

#endif
