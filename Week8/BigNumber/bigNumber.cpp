#include "bigNumber.hpp"
#include <cstring>
#include <iostream>
#define RESIZE_FACTOR 2
#define INITIAL_CAPACITY 255

using namespace std;

void BigNumber::print() {
    // data[fillSize] = '\0';
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
    BigNumber newNumber;
    unsigned int rest = 0;
    long long thisSize = this->fillSize;
    long long otherSize = other.fillSize;
    newNumber.fillSize = (thisSize > otherSize ? thisSize : otherSize);

    while (newNumber.fillSize > newNumber.capacity) {
        newNumber.resize();
    }
    --thisSize;
    --otherSize;
    char thisCurrent;
    char otherCurrent;

    for (int i = newNumber.fillSize - 1; i >= 0; --i) {
        thisCurrent = '0';
        otherCurrent = '0';

        if (thisSize >= 0) {
            thisCurrent = this->data[thisSize];
            --thisSize;
        }

        if (otherSize >= 0) {
            otherCurrent = other.data[otherSize];
            --otherSize;
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
        // ???????????????????? ???? ???????????????????? ???? ???????????? ?? ?????????????? ??????????????,
        // ?????????????? ?????????? ?????? ?????????????? (rest)
        for (int i = newNumber.fillSize - 1; i >= 0; --i) {
            newNumber.data[i + offset] = newNumber.data[i];
        }

        // ?????????????????? ???? ??????????????
        for (int i = offset - 1; i >= 0; --i) {
            newNumber.data[i] = rest % 10 + '0';
            rest /= 10;
        }
    }

    return newNumber;
}

BigNumber BigNumber::operator-(const BigNumber &other) const {
    BigNumber newNumber;
    // unsigned int rest = 0;
    long long thisSize = this->fillSize;
    long long otherSize = other.fillSize;
    newNumber.fillSize = (thisSize > otherSize ? thisSize : otherSize);

    while (newNumber.capacity < newNumber.fillSize) {
        newNumber.resize();
    }
    int thisSizeCpy = thisSize;
    for (int i = newNumber.fillSize; i >=0 && thisSizeCpy >= 0; --i) {
        newNumber.data[i] = this->data[thisSizeCpy--];
    }
    // cout << newNumber.data;

    char thisCurrent;
    char otherCurrent;
    --thisSize;
    --otherSize;
    int diff;
    int newDigit;
    for (int i = newNumber.fillSize; i >= 0; --i) {
        thisCurrent = this->data[thisSize--];
        otherCurrent = other.data[otherSize--];

        diff = thisCurrent - otherCurrent;
        
        if (diff < 0) {
            newDigit = 10 + diff % 10;
            newNumber.data[i - 1] -= diff % 100;
    cout << "*" << newNumber.data << endl;
        }
        else {
            newDigit = diff;
        }

        newNumber.data[i] = newDigit;
    cout << "**" << newNumber.data << endl;
    }

    return newNumber;
}