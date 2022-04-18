#include "bigNumber.hpp"
#include <cstring>
#include <iostream>
#define RESIZE_FACTOR 2
#define INITIAL_CAPACITY 255

using namespace std;

void BigNumber::print() {
    data[fillSize] = '\0';
    cout << data << endl;
}

void BigNumber::resize() {
    capacity *= 2;
    char *newData = new char[capacity];
    strcpy(newData, data);
    delete[] data;
    data = newData;
}

void BigNumber::copyFrom(const BigNumber &other) {
    fillSize = other.fillSize;
    capacity = other.capacity;
    data = new char[capacity];
    strcpy(data, other.data);
}

void BigNumber::free() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    fillSize = 0;
}

BigNumber::BigNumber() {
    capacity = INITIAL_CAPACITY;
    fillSize = 0;
    this->data = new char[capacity];
    strcpy(this->data, "0");
}

BigNumber::BigNumber(const char* data) {
    fillSize = strlen(data);
    capacity = fillSize + INITIAL_CAPACITY;
    this->data = new char[capacity];
    strcpy(this->data, data);
}

BigNumber::BigNumber(const BigNumber &other) {
    copyFrom(other);
}

BigNumber &BigNumber::operator=(const BigNumber &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copyFrom(other);
    return *this;
}

BigNumber::~BigNumber() {
    free();
}

BigNumber BigNumber::operator+(const BigNumber &other) const {
    BigNumber newNumber;// = *this;
    unsigned int rest = 0;
    ull thisSize = this->fillSize;
    ull otherSize = other.fillSize;
    newNumber.fillSize = (thisSize > otherSize ? thisSize : otherSize);

    while (newNumber.fillSize > newNumber.capacity) {
        newNumber.resize();
    }

    // cout << "Capacity: " << newNumber.capacity << endl;
    // cout << "Fill Size " << newNumber.fillSize << endl;

    --thisSize;
    --otherSize;
    char thisCurrent;
    char otherCurrent;

    for (int i = newNumber.fillSize - 1; i >= 0; --i) {
        if (thisSize < 0) {
            thisCurrent = '0';
            otherCurrent = other.data[otherSize--];
        }
        else if (otherSize < 0) {
            thisCurrent = this->data[thisSize--];
            otherCurrent = '0';
        }
        else {
            thisCurrent = this->data[thisSize--];
            otherCurrent = other.data[otherSize--];
        }

        rest += thisCurrent + otherCurrent - 2 * '0';
        newNumber.data[i] = rest % 10 + '0';
        rest /= 10;
    }

    unsigned int offset = 0;
    unsigned int restCpy = rest;
    while (restCpy > 0) {
        restCpy /= 10;
        ++offset;
    }

    newNumber.fillSize += offset;

    if (rest > 0) {
        if (newNumber.fillSize >= newNumber.capacity) {
            newNumber.resize();
        }

        // Изместване на елементите на масива с толкова позиции,
        // колкото цифри има преноса (rest)
        for (int i = newNumber.fillSize - 1; i >= 0; --i) {
            newNumber.data[i + offset] = newNumber.data[i];
        }

        // Записване на преноса
        for (int i = offset - 1; i >= 0; --i) {
            newNumber.data[i] = rest % 10 + '0';
            rest /= 10;
        }
    }

    return newNumber;
}