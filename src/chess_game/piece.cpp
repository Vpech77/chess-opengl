#include "piece.h"
#include "plato.h"
#include <algorithm>
#include <iostream>

Piece::Piece(std::string color, glm::vec2 coord)
    :m_color(color), m_coord(coord), m_typ(TypePiece::WHITE_PAWN)
{

}

Piece::~Piece(){}

TypePiece Piece::getType(){
    return m_typ;
}

void Piece::setType(TypePiece typ){
    m_typ = typ;
}

glm::vec2 Piece::getCoord(){
    return m_coord;
}

std::string Piece::getColor(){
    return m_color;
}

void Piece::move(glm::vec2& newCoord, Plato& board){
    int xcoord = m_coord.x;
    int ycoord = m_coord.y;
    int xnew = newCoord.x;
    int ynew = newCoord.y;
    
    if (board.array[xnew][ynew]){
        glm::vec2 targetPos(xnew, ynew);
        if (board.array[xnew][ynew]->getColor()=="black"){
            std::cout<<"######!(•̀ᴗ•́)و MIAM BlackPiece !(•̀ᴗ•́)و ######\n";
            auto it = std::remove_if(board.blackPieces.begin(), 
                                     board.blackPieces.end(), 
                                     [&targetPos](Piece* p) 
                                     {return p->m_coord == targetPos;});
            board.blackPieces.erase(it, board.blackPieces.end());                         

        }
        else {
            std::cout<<"######!(•̀ᴗ•́)و MIAM WhitePiece !(•̀ᴗ•́)و ######\n";
            auto it = std::remove_if(board.whitePieces.begin(), 
                                     board.whitePieces.end(), 
                                     [&targetPos](Piece* p) 
                                     {return p->m_coord == targetPos;});
            board.whitePieces.erase(it, board.whitePieces.end());
        }

            
        board.array[xnew][ynew] = nullptr;
    }
    
    board.array[xcoord][ycoord] = nullptr;
    m_coord = newCoord;
    board.array[xnew][ynew] = this;
}