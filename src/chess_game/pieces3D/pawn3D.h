#ifndef PAWN3D_H
#define PAWN3D_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <shader.h>
#include <vertexarray.h>
#include <camera.h>
#include <renderer.h>
#include <object.h>

#include "piece3D.h"


class Pawn3D : public Piece3D
{
    public:
        Pawn3D(std::string m_color);

};

#endif
