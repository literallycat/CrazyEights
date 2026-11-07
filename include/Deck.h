//
// Created by jack on 29/10/2026.
//

#ifndef CRAZYEIGHTS_DECK_H
#define CRAZYEIGHTS_DECK_H
#include <list>
#include <vector>

#include "Card.h"


class Deck {
    std::pmr::vector<Card> _cards;
    bool _discard;
    void _generate();
    // static std::string Num2Suit(int number);
    public:
    explicit Deck(bool discard);
    Card draw();
    void shuffle();
    [[nodiscard]] bool isEmpty() const;
    // gets the top card but doesnt remove it!!
    [[nodiscard]] Card getTopCard() const;
    void addCard(const Card& card);


};


#endif //CRAZYEIGHTS_DECK_H
