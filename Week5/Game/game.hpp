#ifndef GAME_HPP
#define GAME_HPP
#define MAX_SIZE 64

class Game {
    char *name = new char[MAX_SIZE];
    double price;
    bool isAvailable;

public:
    Game();
    Game(const char *name, double price, bool isAvailable);

    void setName(const char *name);
    void setPrice(double price);
    void setAvailability(bool isAvailable);

    const char *getName() const;
    double getPrice() const;
    bool getAvailability() const;

    bool isFree() const;
    void print() const;

    ~Game();
};

#endif // GAME_HPP