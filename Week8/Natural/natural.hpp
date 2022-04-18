#pragma once

class NaturalNumber {
private:
    unsigned int num;

public:
    NaturalNumber(unsigned int val = 0);

    bool operator>(const NaturalNumber &rhs) const;
    bool operator<(const NaturalNumber &rhs) const;
    bool operator==(const NaturalNumber &ths) const;

    NaturalNumber operator+(const NaturalNumber &rhs) const;
    NaturalNumber operator-(const NaturalNumber &rhs) const;
    NaturalNumber operator*(const NaturalNumber &rhs) const;
    NaturalNumber operator/(const NaturalNumber &rhs) const;

    NaturalNumber &operator++();
    NaturalNumber operator++(int);
    NaturalNumber &operator--();
    NaturalNumber operator--(int);

    NaturalNumber operator%(const NaturalNumber &rhs) const;
};

// operator++(int) -> a++ (postFix) // copy
// operator++() -> ++a (preFix) // reference