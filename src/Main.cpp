#include <iostream>
#include <list>
#include "../include/Player.h"
#include "../include/GameState.h"
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


Card Player::chooseCard() {
    std::cout << "the top card is: " << this.
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

void Player::mustDraw() {
    // std::cout << "Must draw player" << std::endl;
}
