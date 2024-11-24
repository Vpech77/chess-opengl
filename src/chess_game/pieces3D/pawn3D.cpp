#include "pawn3D.h"
#include <string>
#include <vector>
#include <filesystem>
#include <object.h>

Pawn3D::Pawn3D(std::string m_color): Piece3D(m_color){
    std::string path = std::filesystem::absolute("../src");
    std::vector<glm::vec3> verticesCase;
	std::vector<glm::vec2> uvsCase;
    std::string pathOBJ = path + "/model/pawn.obj";

    oPiece = new Object(pathOBJ.c_str(), path + "/textures/"+color+".png");
}