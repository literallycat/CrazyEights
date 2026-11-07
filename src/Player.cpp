//
// Created by jack on 29/10/2026.
//

#include "../include/Player.h"

#include "../include/Card.h"
#include "../include/Deck.h"

Player::Player(const std::string& name) {
    setName(name);
}

std::list<Card> Player::getCards() {
    return _cards;
}

std::string Player::getName() {
    return _name;
}

void Player::setName(const std::string& name) {
    _name = name;
}

std::list<Card> Player::drawCard(Deck *deck) {
    _cards.push_back(deck->draw());
    return _cards;
}

std::list<Card> Player::drawCard(Deck *deck, int number) {
    for (int i = 0; i < number; ++i) {
        drawCard(deck);
    }
    return _cards;
}

Card Player::removeCard(const Card card) {
    _cards.remove(card);
    return card;
}
