#include "pawn.h"
#include <string>
#include <vector>
#include <filesystem>
#include <object.h>

Pawn::Pawn(std::string m_color): Piece(m_color){
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
    std::string pathOBJ = path + "/model/pawn.obj";

    oPiece = new Object(pathOBJ.c_str(), path + "/textures/"+color+".png");
}

void Pawn::move(int x, int y) {
    oPiece->position.x = x;
    oPiece->position.y= y;
}