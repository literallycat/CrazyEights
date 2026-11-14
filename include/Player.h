//
// Created by jack on 29/10/2026.
//

#ifndef CRAZYEIGHTS_PLAYER_H
#define CRAZYEIGHTS_PLAYER_H
#include <list>
#include <string>

#include "Card.h"
#include "Deck.h"


class Player {
    std::string _name;
    std::vector<Card> _cards;
public:
    Player(const std::string& name);
    std::vector<Card> getCards();
    std::string getName();
    void setName(const std::string& name);
    std::vector<Card> drawCard(Deck *deck);
    std::vector<Card> drawCard(Deck *deck, int number);
    Card removeCard(Card card);
    virtual Card chooseCard();
    virtual void mustDraw();
    
};


#endif //CRAZYEIGHTS_PLAYER_H
