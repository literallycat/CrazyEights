//
// Created by jack on 29/10/2026.
//

#include "../include/Player.h"

#include "../include/Card.h"
#include "../include/Deck.h"

Player::Player(const std::string& name) {
    setName(name);
}

std::vector<Card> Player::getCards() {
    return this->_cards;
}

std::string Player::getName() {
    return this->_name;
}

void Player::setName(const std::string& name) {
    this->_name = name;
}

std::vector<Card> Player::drawCard(Deck *deck) {
    this->_cards.push_back(deck->draw());
    return this->_cards;
}

std::vector<Card> Player::drawCard(Deck *deck, int number) {
    for (int i = 0; i < number; ++i) {
        drawCard(deck);
    }
    return this->_cards;
}

Card Player::removeCard(const Card card) {
    auto it = std::find(this->_cards.begin(), this->_cards.end(), card);
    if (it != this->_cards.end()) {
        this->_cards.erase(it);
    }
    return card;
}
