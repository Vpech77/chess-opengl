#include "king.h"
#include <iostream>

King::King(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_KING);
    }
    else{
        this->setType(TypePiece::BLACK_KING);
    }
}

std::vector<glm::vec2> King::movePossible(Piece* (&array)[8][8]){
    std::vector<glm::vec2> moves;
    int col = this->getCoord().x;
    int li = this->getCoord().y;

    std::vector<glm::vec2> directions = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1,  1}, {0,  1}, {1,  1},
        {-1,  0}, {1,  0}
    };

    for (const auto& dir : directions) {
        int newX = col + dir.x;
        int newY = li + dir.y;
        if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7) {
            if (!array[newX][newY]) {
                moves.push_back({newX, newY});
            } else if (array[newX][newY]->getColor() != array[col][li]->getColor()) {
                moves.push_back({newX, newY});
            }
        }
    }


    // for (const auto& v : moves) { 
    //     std::cout << "(" << v.x << ", " << v.y << ")" << std::endl; 
    // }

    return moves;

}