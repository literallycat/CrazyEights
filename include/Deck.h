//
// Created by jack on 29/10/2026.
//

#ifndef CRAZYEIGHTS_DECK_H
#define CRAZYEIGHTS_DECK_H
#include <list>

#include "Card.h"


class Deck {
    std::vector<Card> _cards;
    bool _discard;
    void _generate();
    static std::string Num2Suit(int number);
    public:
    explicit Deck(bool discard);
    Card draw();
    void shuffle();
    [[nodiscard]] bool isEmpty() const;


};


#endif //CRAZYEIGHTS_DECK_H
