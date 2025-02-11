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

    std::cout<<"------------ Selection --------------\n";
    
    bool isMoveOkay = false;

    int secure = 0;

    while(!isMoveOkay){

        if (board.blackPieces.size() == 0 || board.whitePieces.size()==0){
            break;
        }

        srand(time(NULL));

        // Selection aleatoire de la piece 
        int ind_select = rand() % (isWhiteTurn ? board.whitePieces.size() : board.blackPieces.size());
        Piece * selection = isWhiteTurn ? board.whitePieces.at(ind_select) : board.blackPieces.at(ind_select);
        
        glm::vec2 coord = selection->getCoord();
        std::cout<<"Piece : "<<selection->getType()<<"\n";
        std::cout << "coord (" << coord.x << ", " << coord.y << ")" << std::endl;

        // Selection aleatoire des moves
        std::vector<glm::vec2> movePoss = selection->movePossible(board.array);
        if (!movePoss.empty()){
            int ind_move = rand() % movePoss.size();
            glm::vec2 newcoord = movePoss.at(ind_move);
            std::cout<<"\nind move "<<ind_move<<"\n";
            std::cout << "newCoord (" << newcoord.x << ", " << newcoord.y << ")" << std::endl;

            std::cout<<"------------------ MOVE OK -----------------\n";
            
            selection->move(newcoord, board);
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