#include "bishop.h"
#include <iostream>

Bishop::Bishop(std::string color, glm::vec2 coord): Piece(color, coord)
{
    if (color == "white"){
        this->setType(TypePiece::WHITE_BISHOP);
    }
    else{
        this->setType(TypePiece::BLACK_BISHOP);
    }

}

std::vector<glm::vec2> Bishop::movePossible(Piece* (&array)[8][8]){
    std::vector<glm::vec2> lst;
    int col = this->getCoord().x;
    int li = this->getCoord().y;

    // haut droite
    int x = col;
    int y = li;

    while(x<7 && y<7){
        ++x;
        ++y;
        std::cout<<"x: "<<x<< " y: "<<y<<"\n";
        if (!array[x][y]){
            lst.push_back(glm::vec2(x,y));
        }
        else if (array[x][y]->getColor() != array[col][li]->getColor()){
            lst.push_back(glm::vec2(x,y));
            break;
        }
        else{
            break;
        }
    }

    // haut gauche
    x = col;
    y = li;

    while(x>0 && y<7){
        --x;
        ++y;
        if (!array[x][y]){
            lst.push_back(glm::vec2(x,y));
        }
        else if (array[x][y]->getColor() != array[col][li]->getColor()){
            lst.push_back(glm::vec2(x,y));
            break;
        }
        else{
            break;
        }
    }

    // bas droite
    x = col;
    y = li;

    while(x<7 && y>0){
        ++x;
        --y;
        if (!array[x][y]){
            lst.push_back(glm::vec2(x,y));
        }
        else if (array[x][y]->getColor() != array[col][li]->getColor()){
            lst.push_back(glm::vec2(x,y));
            break;
        }
        else{
            break;
        }
    }

    // bas gauche
    x = col;
    y = li;

    while(x>0 && y>0){
        --x;
        --y;
        if (!array[x][y]){
            lst.push_back(glm::vec2(x,y));
        }
        else if (array[x][y]->getColor() != array[col][li]->getColor()){
            lst.push_back(glm::vec2(x,y));
            break;
        }
        else{
            break;
        }
    }


    for (const auto& v : lst) { 
        std::cout << "(" << v.x << ", " << v.y << ")" << std::endl; 
    }
    return lst;
}
