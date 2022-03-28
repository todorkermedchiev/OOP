#include <iostream>
#include <fstream>
#include "gamePlatform.hpp"
#include "game.hpp"

#define DEFAULT_GAMES_COUNT 10

using namespace std;

GamePlatform::GamePlatform() {
    list = new Game[DEFAULT_GAMES_COUNT];
    gamesCount = 0;
}

GamePlatform::GamePlatform(unsigned int maxCount) {
    list = new Game[maxCount];
    gamesCount = 0;
    this->maxCount = maxCount;
}

void GamePlatform::addGame(const char *name, double price, bool isAvailable) {
    if (gamesCount >= maxCount) {
        return;
    }
    list[gamesCount] = Game(name, price, isAvailable);
    ++gamesCount;
}

void GamePlatform::printGameByIndex(unsigned int index) const{
    if (index < 0 || index >= gamesCount) {
        return;
    }

    list[index].print();
}

void GamePlatform::printGamesList() const {
    for (int i = 0; i < gamesCount; ++i) {
        list[i].print();
        cout << "--------------------\n";
    }
}

void GamePlatform::printCheapestGame() const{
    int index = 0;
    for (int i = 0; i < gamesCount; ++i) {
        if (list[i].getPrice() < list[index].getPrice()) {
            index = i;
        }
    }

    list[index].print();
}

void GamePlatform::printMostExpensiveGame() const {
    int index = 0;
    for (int i = 0; i < gamesCount; ++i) {
        if (list[i].getPrice() > list[index].getPrice()) {
            index = i;
        }
    }

    list[index].print();
}

void GamePlatform::printFreeGames() const{
    for (int i = 0; i < gamesCount; ++i) {
        if (list[i].isFree()) {
            list[i].print();
            cout << "--------------------\n";
        }
    }
}

void GamePlatform::removeGame(unsigned int index) {
    if (index < 0 || index >= gamesCount) {
        return;
    }

    for (int i = index + 1; i < gamesCount; ++i) {
        list[i - 1] = list[i];
    }

    gamesCount--;
}

GamePlatform::~GamePlatform() {
    delete[] list;
}