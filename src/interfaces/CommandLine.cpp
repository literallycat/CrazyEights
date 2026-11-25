//
// Created by jack on 12/11/2026.
//

#include <iostream>
#include <list>
#include "../../include/Player.h"
#include "../../include/GameState.h"

using namespace std;

int main() {
    int NumOfPlayers = 0;
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
        }
    } while (NumOfPlayers <=     1);
    for (int i = 0; i < NumOfPlayers; i++) {
        std::string name;
        cout << "enter player name: ";
        cin >> name;
        players.emplace_back(name);
    }
    auto game=  GameState(players);
    game.mainLoop();
    return 0;
}


Card Player::chooseCard(Card topCard) {
    std::cout << "the top card is: " << topCard.getValStr() << " of " << topCard.getSuit() << std::endl;
    std::cout << this->getName() << ", Choose your card: " << endl;
    int counter = 1;
    for (auto card: this->_cards) {
        cout << counter << ": " << card.getValStr() << " of " << card.getSuit() << endl;
        counter++;
    }
    int selectedCard;
    cin >> selectedCard;
    return _cards[selectedCard-1];
}

void Player::mustDraw(Card topCard) {
    std::cout << "Must draw player" << std::endl;
    this->win();
}

void GameState::playerWon(Player &player) {
    std::cout << "player " << player.getName() <<  "won!" << std::endl;
    std::cout << "they now have " << player.getPlayerScore() <<  "points!" << std::endl;
}

Suit GameState::declareNewSuit() {
    int selectedSuit;
    bool valid = false;
    std::cout << "you played an 8!" << std::endl;
    while (!valid) {
        std::cout << "select your desired suit: " << std::endl;
        for (size_t index = 0; index < Suit::_size(); ++index) {
            const char  *name = Suit::_names()[index];
            std::cout << index+1 << ": " << name << " " << std::endl;
        }
        std::cout << std::endl;
        cin >> selectedSuit;
        if (cin.fail() || !Suit::_is_valid(selectedSuit-1)) {
            cin.clear();
            cin.ignore();
            std::cout << "invalid input! " << std::endl;
        } else {
            valid = true;
        }
    }


    return Suit::_from_integral(selectedSuit-1);
}
