#ifndef PIECE_H
#define PIECE_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <shader.h>
#include <vertexarray.h>
#include <camera.h>
#include <renderer.h>
#include <object.h>


class Piece
{
    public:
        Piece(int x, int y);
        ~Piece();
        Object* oPiece;
        void Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer);
        int m_x;
        int m_y;
    
};

#endif
