#include <iostream>
#include <list>

#include "../include/Player.h"

using namespace std;

int main() {
    int NumOfPlayers = 0;
    list<Player> players;
    auto deck = Deck(false);
    auto discard = Deck(true);
    do{
        cout << "enter number of players: " << endl;
        cin >> NumOfPlayers;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "enter number pls :( " << endl;
        }
        if (NumOfPlayers == 1 || NumOfPlayers == 0) {
            cout << "too little players to start a game!" << endl;
        }
    } while (NumOfPlayers == 0 || NumOfPlayers == 1);
    for (int i = 0; i < NumOfPlayers; i++) {
        std::string name;
        cout << "enter player name: ";
        cin >> name;
        players.emplace_back(name);
    }
    for (auto player: players) {
        cout << player.getName() << endl;
        if (NumOfPlayers == 2) {
            player.drawCard(&deck,7);
        } else {
            player.drawCard(&deck, 5);
        }
    }
    discard.addCard(deck.draw());
    cout << "the top card on the discard pile is: " << discard.getTopCard().getValStr() << " of " << discard.getTopCard().getSuit() << endl;

    return 0;
}