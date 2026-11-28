//
// Created by jack on 29/10/2026.
//

#ifndef CRAZYEIGHTS_PLAYER_H
#define CRAZYEIGHTS_PLAYER_H
#pragma once
#include <list>
#include <string>

#include "Card.h"
#include "Deck.h"


class Player {
    std::string _name;
    std::vector<Card> _cards;
    int _score;
public:
    Player(const std::string& name);
    std::vector<Card> getCards();
    std::string getName();
    int getHandScore();
    int getPlayerScore();
    void setScore(int score);
    void setName(const std::string& name);
    std::vector<Card> drawCard(Deck *deck);
    std::vector<Card> drawCard(Deck *deck, int number);
    Card removeCard(Card card);
    virtual Card chooseCard(Card topCard);
    virtual void mustDraw(Card topCard);

    
};


#endif //CRAZYEIGHTS_PLAYER_H
