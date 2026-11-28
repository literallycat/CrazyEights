//
// Created by jack on 29/10/2026.
//

#include "../include/Player.h"

#include <algorithm>

#include "../include/Card.h"
#include "../include/Deck.h"

Player::Player(const std::string& name) {
    setName(name);
    // thanks macOS for hiding this bug from me
    _score = 0;
}

std::vector<Card> Player::getCards() {
    return this->_cards;
}

std::string Player::getName() {
    return this->_name;
}


int Player::getHandScore() {
    int handValue = 0;
    for (auto cards: this->_cards) {
        int cardVal = cards.getVal();
        if (cardVal == 8) {
            handValue += 50;
        } else if (cardVal >=10) {
            handValue += 10;
        } else {
            handValue += cardVal;
        }
    }
    return handValue;
}

int Player::getPlayerScore() {return this->_score;}

void Player::setScore(int score) {
    this->_score = score;
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
// uses the operator created in the card class
Card Player::removeCard(const Card card) {
    auto it = std::ranges::find(this->_cards.begin(), this->_cards.end(), card);
    if (it != this->_cards.end()) {
        this->_cards.erase(it);
    }
    return card;
}
