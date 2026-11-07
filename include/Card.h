//
// Created by jack on 29/10/2026.
//
// card is header only cause im using it more like a struct than a class

#ifndef CRAZYEIGHTS_CARD_H
#define CRAZYEIGHTS_CARD_H
#include <string>
#include "vendor/enum.h"

BETTER_ENUM(Suit, int, Diamonds,Clubs,Hearts,Spades);
class Card {
    int _internalVal = 0;
    // defualt to make the compiler happy
    Suit suit = Suit::Diamonds;
public:
        Card(int value, Suit suit) {
        this->_internalVal = value;
        this->suit = suit;
    }

    [[nodiscard]] int getVal() const {
            return this->_internalVal;
        }
    [[nodiscard]] Suit getSuit() const {
            return this->suit;
        }
    [[nodiscard]] std::string getValStr() const {
            switch (this->_internalVal) {
                case 1:
                    return "Ace";
                case 11:
                    return "Jack";
                case 12:
                    return "Queen";
                case 13:
                    return "King";
                default: return std::to_string(this->_internalVal);
            }
        }
    // operators allow me to use contains-like functions
    bool operator==(const Card& card) const {
                if (this->getVal() == card.getVal() && this->getSuit() == card.getSuit()) {
                    return true;
                }
            return false;
            }
        };

#endif //CRAZYEIGHTS_CARD_H
