//
// Created by jack on 07/11/2026.
//

#ifndef CRAZYEIGHTS_GAMESTATE_H
#define CRAZYEIGHTS_GAMESTATE_H
#include <list>

#include "Player.h"


class GameState {
    void runTurn(Player player);
    std::list<Player> _players;
    Deck _deck;
    Deck _discard;
    public:
    explicit GameState(const std::list<Player>& players);
    void mainLoop();

};



#endif //CRAZYEIGHTS_GAMESTATE_H
