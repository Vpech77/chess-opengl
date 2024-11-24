#include "piece3D.h"


Piece3D::Piece3D(std::string m_color): oPiece(nullptr), color(m_color)
{

}

Piece3D::~Piece3D()
{
    delete oPiece;
}

void Piece3D::Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer) 
{
    if (oPiece != nullptr) { 
        glm::mat4 m = oPiece->getModelMatrix();
        glm::mat4 v = cam.getViewMatrix();
        glm::mat4 p = cam.getProjectionMatrix();
        glm::mat4 mvp = p*v*m;
        shader.setUniformMat4f("MVP", mvp);
        renderer.Draw(va, *oPiece, shader);
    }
}