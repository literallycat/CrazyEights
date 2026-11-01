//
// Created by jack on 29/10/2026.
//
// card is header only cause im using it more like a struct than a class

#ifndef CRAZYEIGHTS_CARD_H
#define CRAZYEIGHTS_CARD_H
#include <string>


class Card {
    int _internalVal = 0;
    std::string suit;
    public:
        Card(int value, std::string suit) {
            this->_internalVal = value;
            this->suit = suit;
        }
    [[nodiscard]] int getVal() const {
            return this->_internalVal;
        }
    std::string getSuit() {
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
};
#endif //CRAZYEIGHTS_CARD_H
