#ifndef GAMEPLATFORM_HPP
#define GAMEPLATFORM_HPP

#include "game.hpp"

class GamePlatform {
    Game *list;
    int gamesCount;
    int maxCount;

public:
    GamePlatform();
    GamePlatform(unsigned int maxCount);

    void addGame(const char *name, double price, bool isAvailable);
    void printGameByIndex(unsigned int index) const;
    void printGamesList() const;
    void printCheapestGame() const;
    void printMostExpensiveGame() const;
    void printFreeGames() const;
    void removeGame(unsigned int index);

    void saveGameList(char *path);
    void readGameList(char *path);

    ~GamePlatform();
};

#endif // GAMEPLATFORM_HPP