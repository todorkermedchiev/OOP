#include <iostream>
#include "game.hpp"
#include "../../myString.hpp"

using namespace std;

Game::Game() {
    setName("");
    setPrice(0);
    setAvailability(false);
}

Game::Game(const char *name, double price, bool isAvailable) {
    setName(name);
    setPrice(price);
    setAvailability(isAvailable);
}

void Game::setName(const char *name) {
    if (name == nullptr) {
        return;
    }
    strCpy(name, this->name);
}

void Game::setPrice(double price) {
    if (price < 0) {
        this->price = 0;
        return;
    }
    this->price = price;
}

void Game::setAvailability(bool isAvailable) {
    this->isAvailable = isAvailable;
}

const char *Game::getName() const {
    const char *name = this->name;
    return name;
}

double Game::getPrice() const {
    return price;
}

bool Game::getAvailability() const {
    return isAvailable;
}

bool Game::isFree() const {
    return price == 0;
}

void Game::print() const {
    cout << name << endl;
    cout << "Price: " << price << endl;
    cout << "Available: " << (isAvailable ? "Yes" : "No") << endl;
}

Game::~Game() {
    delete[] name;
}