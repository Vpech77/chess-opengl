#include "piece.h"
#include <filesystem>

Piece::Piece(int x, int y): oPiece(nullptr), m_x(x), m_y(y)
{
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
    std::string pathOBJ = path + "/model/pawn.obj";

    oPiece = new Object(pathOBJ.c_str(), path + "/textures/noir.png");
}

Piece::~Piece()
{
    delete oPiece;
}

void Piece::Draw(VertexArray& va, Camera& cam, Shader& shader, Renderer& renderer) 
{
    oPiece->position.x = m_x;
    oPiece->position.y = m_y;
    glm::mat4 m = oPiece->getModelMatrix();
    glm::mat4 v = cam.getViewMatrix();
    glm::mat4 p = cam.getProjectionMatrix();
    glm::mat4 mvp = p*v*m;
    shader.setUniformMat4f("MVP", mvp);
    renderer.Draw(va, *oPiece, shader);
}