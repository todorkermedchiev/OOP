#include "car.hpp"
#include <cstring>

void Car::copyName(const char *name) {
    size_t length = strlen(name);
    this->name = new char[length + 1];
    strcpy(this->name, name);
}

void Car::copyFrom(const Car &other) {
    copyName(other.name);
    year = other.year;
}

void Car::free() {
    delete[] name;
    name = nullptr;
}

Car::Car() : name(nullptr), year(0) {
    copyName("");
}

Car::Car(const char *name, unsigned int year) : name(nullptr), year(year) {
    copyName(name);
}

Car::Car(const Car &other) {
    copyFrom(other);
}

Car& Car::operator=(const Car &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Car::~Car() {
    free();
}

const char* Car::getName() const {
    return name;
}

unsigned int Car::getYear() const {
    return year;
}

void Car::setName(const char *name) {
    delete[] this->name;
    copyName(name);
}

void Car::setYear(unsigned int year) {
    this->year = year;
}
