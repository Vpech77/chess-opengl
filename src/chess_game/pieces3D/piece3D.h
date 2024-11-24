#ifndef PIECE3D_H
#define PIECE3D_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <shader.h>
#include <vertexarray.h>
#include <camera.h>
#include <renderer.h>
#include <object.h>

class Piece3D
{
    public:
        Piece3D(std::string m_color);
        virtual ~Piece3D();
        std::string color;
        Object* oPiece;
        void Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer);
};

#endif
