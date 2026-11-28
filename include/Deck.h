//
// Created by jack on 29/10/2026.
//

#ifndef CRAZYEIGHTS_DECK_H
#define CRAZYEIGHTS_DECK_H
#pragma once
#include <list>
#include <vector>

#include "Card.h"


class Deck {
    std::pmr::vector<Card> _cards;
    bool _discard;
    void _generate();
    public:
    explicit Deck(bool discard);
    Card draw();
    void shuffle();
    [[nodiscard]] bool isEmpty() const;
    // gets the top card but doesn't remove it!!
    [[nodiscard]] Card getTopCard() const;
    void addCard(const Card& card);
    // changes if its a discard or draw pile
    void flip();


};


#endif //CRAZYEIGHTS_DECK_H
