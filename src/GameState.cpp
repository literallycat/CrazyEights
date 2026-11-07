//
// Created by jack on 07/11/2026.
//

#include "../include/GameState.h"

#include <algorithm>
#include <iostream>


// im trying the best to make it portable >.< even though i dont need to.....
void GameState::runTurn(Player player) {
    std::list<Card> playableCards;
    auto discardCard = _discard.getTopCard();
    do {
        for (auto card: player.getCards()) {
            if (discardCard.getSuit() == card.getSuit() || discardCard.getVal() == card.getVal()) {
                playableCards.push_back(card);
            }
        }
        if (playableCards.empty()) {
            player.mustDraw();
        }
    } while (playableCards.empty());
    Card chosen = player.chooseCard();
    if (std::ranges::contains(playableCards, chosen)) {
        _discard.addCard(chosen);
    }

}


GameState::GameState(const std::list<Player>& players) : _deck(false), _discard(true) {
    this->players = players;
    const int NumOfPlayers = players.size();
    for (auto player: players) {
        std::cout << player.getName() << std::endl;
        if (NumOfPlayers == 2) {
            player.drawCard(&_deck, 7);
        } else {
            player.drawCard(&_deck, 5);
        }
    }
    _discard.addCard(_deck.draw());
    std::cout << "the top card on the discard pile is: " << _discard.getTopCard().getValStr() << " of " << _discard.
            getTopCard().getSuit() << std::endl;
}
