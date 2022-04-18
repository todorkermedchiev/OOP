#ifndef BIGNUMBER_HPP
#define BIGNUMBER_HPP
typedef unsigned long long int ull;

class BigNumber {
private:
    char *data;
    ull capacity;
    ull fillSize;

    void copyFrom(const BigNumber &other);
    void free();
    void resize();

public:
    BigNumber();
    BigNumber(const char *data);
    BigNumber(const BigNumber &other);
    BigNumber &operator=(const BigNumber &other);
    ~BigNumber();

    void print();

    BigNumber operator+(const BigNumber &other) const;
    BigNumber operator-(const BigNumber &other) const;
    BigNumber operator*(const BigNumber &other) const;
    BigNumber operator/(const BigNumber &other) const;
    
};

#endif // BIGNUMBER_HPP