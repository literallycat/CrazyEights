//
// Created by jack on 07/11/2026.
//

#ifndef CRAZYEIGHTS_GAMESTATE_H
#define CRAZYEIGHTS_GAMESTATE_H
#pragma once
#include <list>

#include "Player.h"


class GameState {
    void runTurn(Player& player);
    std::list<Player> _players;
    Deck _deck;
    Deck _discard;
    void swapDecks();
    public:
    explicit GameState(const std::list<Player>& players);
    void mainLoop();
    Card getTopCard() const;
    int doScoring(Player& player);
    virtual void playerWon(Player& player);
    virtual Suit declareNewSuit();
};



#endif //CRAZYEIGHTS_GAMESTATE_H
