#include "game.h"
#include <string>

Game::Game(): isWhiteTurn(true) {

}

Game::~Game(){

}

void Game::playTurn(){

    std::string turn = isWhiteTurn ? "Blancs" : "Noirs";

    std::cout<<"------------------ Tour des "+ turn +" -----------------\n";

    int nbCase = 8;
    int tailleCase = 2;

    for (int i=0; i<nbCase; i++){
        for (int j=0; j<nbCase; j++){
            if(board.array[i][j]){
                std::cout<<"Piece ("<<i<<","<<j<<")\n";
                std::cout<<"Move :\n";
                std::vector<glm::vec2> t = board.array[i][j]->movePossible(board.array);
                std::cout<<"-------------------------------\n";
            }
        }
    }
    std::cout<<"------------ Selection --------------\n";
    
    bool isMoveOkay = false;

    int secure = 0;

    while(!isMoveOkay){
        // Selection aleatoire de la piece 
        int ind_select = rand() % (isWhiteTurn ? board.whitePieces.size() : board.blackPieces.size());
        Piece * selection = isWhiteTurn ? board.whitePieces.at(ind_select) : board.blackPieces.at(ind_select);
        
        glm::vec2 coord = selection->getCoord();
        std::cout<<"Piece\n";
        std::cout << "coord (" << coord.x << ", " << coord.y << ")" << std::endl;

        // Selection aleatoire des moves
        std::vector<glm::vec2> movePoss = selection->movePossible(board.array);
        if (!movePoss.empty()){
            int ind_move = rand() % movePoss.size();
            glm::vec2 newcoord = movePoss.at(ind_move);
            std::cout<<"ind move "<<ind_move<<"\n";
            std::cout << "newCoord (" << newcoord.x << ", " << newcoord.y << ")" << std::endl;

            std::cout<<"------------------ MOVE OK -----------------\n";
            
            selection->move(newcoord, board.array);
            isMoveOkay = true;
            isWhiteTurn = !isWhiteTurn;
        }
        else {
            std::cout<<"------------------ Mouv impossible -----------------\n";

            std::string turn = isWhiteTurn ? "Blancs" : "Noirs";
            std::cout<<"------------------ Tour des "+ turn +" encore -----------------\n";
            secure++;
            std::cout<<"secure : "<<secure<<"\n";
            if (secure == 10){
                std::cout<<"secure in if : "<<secure<<"\n";
                break;
            }
        }
    }

}