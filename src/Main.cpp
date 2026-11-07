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
    new GameState(players);



    return 0;
}