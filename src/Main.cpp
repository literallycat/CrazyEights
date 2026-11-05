#include <iostream>
#include <list>

#include "../include/Player.h"

using namespace std;
int main() {
    int NumOfPlayers;
    std::list<Player> players;
    auto deck = Deck(false);
    cout << "enter number of players: " << endl;
    cin >> NumOfPlayers;
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

    return 0;
}