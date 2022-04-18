#include "natural.hpp"
#include <iostream>

using namespace std;

NaturalNumber::NaturalNumber(unsigned int val) {
    num = val;
}

bool NaturalNumber::operator<(const NaturalNumber &rhs) const {
    return this->num < rhs.num;
}

bool NaturalNumber::operator>(const NaturalNumber &rhs) const {
    return this->num > rhs.num;
}

bool NaturalNumber::operator==(const NaturalNumber &rhs) const {
    return this->num == rhs.num;
}

NaturalNumber NaturalNumber::operator+(const NaturalNumber &rhs) const {
    return NaturalNumber(this->num + rhs.num);
}

NaturalNumber NaturalNumber::operator-(const NaturalNumber &rhs) const {
    if (this->num - rhs.num < 0) {
        cout << "The result is not a natural number!\n";
        return NaturalNumber();
    }
    return NaturalNumber(this->num + rhs.num);
}

NaturalNumber NaturalNumber::operator*(const NaturalNumber &rhs) const {
    return NaturalNumber(this->num * rhs.num);
}

NaturalNumber NaturalNumber::operator/(const NaturalNumber &rhs) const {
    if (rhs.num == 0) {
        cout << "err";
        return NaturalNumber();
    }
    return NaturalNumber(this->num / rhs.num);
}

NaturalNumber &NaturalNumber::operator++() { // prefix
    ++num;
    return *this;
}

NaturalNumber NaturalNumber::operator++(int) { // postfix
    NaturalNumber oldVal = *this;
    // ++(*this);
    // this->operator++();
    ++num;
    return oldVal;
}

NaturalNumber &NaturalNumber::operator--() { // prefix
    if (num == 0) {
        return *this;
    }

    --num;
    return *this;
}

NaturalNumber NaturalNumber::operator--(int) { // postfix
    if (num == 0) {
        return NaturalNumber();
    }

    NaturalNumber oldVal = *this;
    --num;
    return oldVal;
}

NaturalNumber NaturalNumber::operator%(const NaturalNumber &rhs) const {
    return NaturalNumber(num % rhs.num);
}