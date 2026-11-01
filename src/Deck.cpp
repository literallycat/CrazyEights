//
// Created by jack on 29/10/2026.
//

#include "../include/Deck.h"

#include <iostream>
#include <random>

Deck::Deck(const bool discard) {
    _discard = discard;
    if (!discard) {
        _generate();
    }
}

Card Deck::draw() {
    if (_discard) {
        throw std::logic_error("Deck::draw() on discard pile!!");
    }
    Card drawn = _cards.front();
    _cards.erase(_cards.begin());
    return drawn;
}

// im not using the template but i stole the shuffle code sowwy :(
void Deck::shuffle()
{
    if (_discard) {
        throw std::logic_error("Deck::shuffle() on discard pile!!");
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::ranges::shuffle(this->_cards, g);
}

bool Deck::isEmpty() const {
    if (_cards.empty()) {
        return true;
    }
    return false;
}

std::string Deck::Num2Suit(const int number) {
    switch (number) {
        case 0:
            return "Diamonds";
        case 1:
            return "Clubs";
        case 2:
            return "Hearts";
        case 3:
            return "Spades";
        default: return "";
    }
}

void Deck::_generate() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            Card card = _cards.emplace_back(j+1,Num2Suit(i));
            std::cout << card.getValStr() << " of " << card.getSuit() << std::endl;
        }
    }
}



