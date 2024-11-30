#ifndef GAME_H
#define GAME_H

#include "plato.h"

class Game {
public:
    Game();
    ~Game();
    void playTurn();
    Plato board;
private:
    bool isWhiteTurn;
};

#endif