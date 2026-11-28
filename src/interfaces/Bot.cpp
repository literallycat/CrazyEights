//
// Created by jack on 26/11/2026.
//


#include <iostream>
#include <list>
#include <random>

#include "../../include/Player.h"
#include "../../include/GameState.h"

using namespace std;

int main() {
    std::array<std::string,7> botName = {"April", "Jane", "Quinn", "Noelle", "Sophie","Nina","Lowri"};
    int NumOfPlayers;
    list<Player> players;
    do{
        cout << "enter number of players: " << endl;
        cin >> NumOfPlayers;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "enter number pls :( " << endl;
        } else if (NumOfPlayers <= 1 ) {
            cout << "too little players to start a game!" << endl;
        } else if (NumOfPlayers > 7 ) {
            cout << "too many players to start a game!" << endl;
        }
    } while (NumOfPlayers <= 1);
    for (int i = 0; i <= NumOfPlayers-1; i++) {
        players.emplace_back(botName[i]);
    }
    auto game=  GameState(players);
    game.mainLoop();
}

Card Player::chooseCard(Card topCard) {
    std::cout << "the top card is: " << topCard.getValStr() << " of " << topCard.getSuit() << std::endl;
    std::cout << this->getName() << ", Choose your card: " << endl;
    int counter = 1;
    vector<Card> playableCards;
    for (auto card: _cards) {
        cout << counter << ": " << card.getValStr() << " of " << card.getSuit() << endl;
        if (card.getSuit() == topCard.getSuit() || card.getVal() == topCard.getVal() || card.getVal() == 8) {
            playableCards.push_back(card);
        }
        counter++;
    }


    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, playableCards.size() - 1);
    return playableCards[distr(eng)];
}

void Player::mustDraw(Card topCard) {
    std::cout << "Must draw player" << std::endl;
}

void GameState::playerWon(Player &player) {
    std::cout << "player " << player.getName() <<  " won!" << std::endl;
    std::cout << "they now have " << player.getPlayerScore() <<  " points!" << std::endl;
    std::exit(9999);
}

Suit GameState::declareNewSuit() {
    return Suit::_from_integral(rand() % 3);
}
