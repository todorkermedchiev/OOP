#include "rational.hpp"
#include <numeric>
#include <fstream>

Rational::Rational(int n, int d) : numerator(n)
{
    if (d != 0)
    {
        denominator = d;
        simplify();
    }
    else
    {
        denominator = 1;
    }
}

int Rational::getNumerator(/* Rational const * const this */) const
{
    return numerator;
}

int Rational::getDenominator(/* Rational const * const this */) const
{
    return denominator;
}

bool Rational::setNumerator(/* Rational * const this, */ int n)
{
    numerator = n;
    simplify();
    return true;
}

bool Rational::setDenominator(/* Rational * const this, */ int d)
{
    if (d != 0)
    {
        denominator = d;
        simplify();
        return true;
    }
    return false;
}

Rational Rational::add(/* Rational const * const this, */ const Rational &rhs) const
{
    Rational r;
    r.numerator = numerator * rhs.denominator + rhs.numerator * denominator;
    r.denominator = denominator * rhs.denominator;
    r.simplify();
    return r;
}

Rational Rational::subtract(/* Rational const * const this, */ const Rational &rhs) const
{
    Rational r;
    r.numerator = numerator * rhs.denominator - rhs.numerator * denominator;
    r.denominator = denominator * rhs.denominator;
    r.simplify();
    return r;
}

Rational Rational::multiply(/* Rational const * const this, */ const Rational &rhs) const
{
    return Rational(numerator * rhs.numerator, denominator * rhs.denominator);
}

Rational Rational::divide(/* Rational const * const this, */ const Rational &rhs) const
{
    return Rational(numerator * rhs.denominator, denominator * rhs.numerator);
}

void Rational::simplify(/* Rational * const this */ )
{
    int gcd = std::gcd(numerator, denominator); //available from c++17 (#include <numeric>)
    numerator /= gcd;
    denominator /= gcd;
}

void Rational::print(/* Rational const * const this, */ std::ostream &os) const {
  os << this->numerator << " / " << this->denominator;
}

void Rational::serialize(/* Rational const * const this, */ std::ostream &os) const {
  os.write((const char*)this, sizeof(Rational));
}

Rational Rational::read(std::istream &is) {
  Rational r;
  char c;
  
  is >> r.numerator;
  is >> c; // for '/'
  is >> r.denominator;

  return r;
}

Rational Rational::deserialize(std::istream &is) {
  Rational r;
  is.read((char *)&r, sizeof(r));
  return r;
}

Rational Rational::operator+(const Rational &rhs) const {
    Rational newNumber;
    newNumber.setNumerator(numerator * rhs.denominator + rhs.numerator * denominator);
    newNumber.setDenominator(denominator * rhs.denominator);
    newNumber.simplify();
    return newNumber;
}

Rational Rational::operator-(const Rational &rhs) const {
    Rational newNumber;
    newNumber.setNumerator(numerator * rhs.denominator - rhs.numerator * denominator);
    newNumber.setDenominator(denominator * rhs.denominator);
    newNumber.simplify();
    return newNumber;
}

Rational Rational::operator*(const Rational &rhs) const {
    Rational newNumber;
    newNumber.setNumerator(numerator * rhs.numerator);
    newNumber.setDenominator(denominator * rhs.denominator);
    newNumber.simplify();
    return newNumber;
}

Rational Rational::operator/(const Rational &rhs) const {
    Rational newNumber;
    newNumber.setNumerator(numerator * rhs.denominator);
    newNumber.setDenominator(denominator * rhs.numerator);
    newNumber.simplify();
    return newNumber;
}

Rational &Rational::operator+(int num) const {
    Rational newNum;
    newNum.setNumerator(numerator + num * denominator);
    return newNum;
}

Rational &operator+(int num, const Rational &rat) {
    Rational newNum;
    newNum.setNumerator(rat.numerator + num * rat.denominator);
    return newNum;
}

Rational &Rational::operator+=(const Rational &rhs) {
    setNumerator(numerator * rhs.denominator + rhs.numerator * denominator);
    setDenominator(denominator * rhs.denominator);
    simplify();
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs) {
    setNumerator(numerator * rhs.denominator - rhs.numerator * denominator);
    setDenominator(denominator * rhs.denominator);
    simplify();
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs) {
    setNumerator(numerator * rhs.numerator);
    setDenominator(denominator * rhs.denominator);
    simplify();
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs) {
    setNumerator(numerator * rhs.denominator);
    setDenominator(denominator * rhs.numerator);
    simplify();
    return *this;
}

// prefix
Rational &Rational::operator++() {
    Rational oldVal = *this;
    setNumerator(numerator + denominator);
    simplify();
    return oldVal;
}

// може би са обратно
// postfix
// Rational &Rational::operator++(int) {
//     setNumerator(numerator + denominator);
//     simplify();
//     return *this;
// }

// // prefix
// Rational &Rational::operator--() {
//     Rational oldVal = *this;
//     setNumerator(numerator - denominator);
//     simplify();
//     return oldVal;
// }

// // postfix
// Rational &Rational::operator--(int) {
//     setNumerator(numerator - denominator);
//     simplify();
//     return *this;
// }

std::ostream &operator<<(std::ostream &os, const Rational &number) {
    os << number.numerator << '/' << number.denominator; 
    return os;
}

std::istream &operator>>(std::istream &is, Rational &number) {
    int numerator, denominator;
    char c;
    is >> numerator >> c >> denominator;
    number.setNumerator(numerator);
    number.setDenominator(denominator);
    number.simplify();
    return is;
}
