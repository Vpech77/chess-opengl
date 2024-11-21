#ifndef PLATO_H
#define PLATO_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <shader.h>
#include <vertexarray.h>
#include <camera.h>
#include <renderer.h>
#include "object.h"

class Plato
{
    private:
        void renderCase(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer, Object& o, glm::vec3& pos);
        
    public:
        Plato();
        ~Plato();
        void Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer);
        Object* caseBlack;
        Object* caseWhite;
        

};

#endif
