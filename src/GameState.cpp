//
// Created by jack on 07/11/2026.
//

#include "../include/GameState.h"

#include <algorithm>
#include <iostream>


// im trying the best to make it portable >.< even though i dont need to.....
void GameState::runTurn(Player& player) {
    std::list<Card> playableCards;
    auto discardCard = _discard.getTopCard();
    // pre-calculate valid card placements
    do {
        for (auto card: player.getCards()) {
            if (discardCard.getSuit() == card.getSuit() || discardCard.getVal() == card.getVal() || card.getVal() == 8) {
                playableCards.push_back(card);
            }
        }
        if (playableCards.empty()) {
            player.mustDraw(_discard.getTopCard());
        }
    } while (playableCards.empty());

    if (Card chosen = player.chooseCard(_discard.getTopCard()); std::ranges::contains(playableCards, chosen)) {
        if (chosen.getVal() == 8) {
            Suit suit = declareNewSuit();
            _discard.addCard(Card(8,suit));
        }
        else {
            _discard.addCard(chosen);
        }
        player.removeCard(chosen);
    }
    if (player.getCards().empty()) {
        // player won
        this->playerWon(player);
    }

}


GameState::GameState(const std::list<Player>& players) : _deck(false), _discard(true) {
    this->_players = players;
    const int NumOfPlayers = players.size();
    for (auto& player: _players) {
        std::cout << player.getName() << std::endl;
        if (NumOfPlayers == 2) {
            player.drawCard(&_deck, 7);
        } else {
            player.drawCard(&_deck, 5);
        }
    }
    _discard.addCard(_deck.draw());
}

void GameState::mainLoop() {
    while (true) {
        for (Player& player : _players) {
            runTurn(player);
        }
    }
}

Card GameState::getTopCard() const {
    return _discard.getTopCard();
}
int GameState::doScoring(Player& player) {
    int playerScore =0;
    for (auto players: _players) {
        if (players.getName() == player.getName()) {
            continue;
        }
        playerScore += players.getHandScore();
    }
    player.setScore(player.getPlayerScore() + playerScore);
    return playerScore;
}


