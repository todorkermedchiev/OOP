#include <iostream>
#include "game.hpp"
#include "gamePlatform.hpp"

using namespace std;

int main() {
    GamePlatform gamesList(5);
    gamesList.addGame("asdfhvnj", 12, true);
    gamesList.addGame("adff", 5.5, false);
    gamesList.addGame("mamam", 6.8, true);
    gamesList.addGame("free", 0.0, true);
    gamesList.removeGame(1);
    // cout << gamesList.gamesCount;

    // gamesList.printGamesList();

    return 0;
}