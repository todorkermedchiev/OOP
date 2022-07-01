#include "myString.hpp"
#include <cstring>
#include <iostream>
#include <iomanip>

void String::copyFrom(const String& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy(str, other.str);
	size = other.size;
}
void String::free()
{
	delete[] str;
}

String::String(const char* data)
{
	if(data == nullptr)
	{
		str = new char[1];
		str[0] = '\0';
		size = 0;
	}
	else
	{
		size = strlen(data);
		str = new char[size + 1];
		strcpy(str, data);
	}
}

size_t getNumSize(size_t num)
{
	size_t res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return res;
}
String::String(size_t n)
{
	int numSize = getNumSize(n);
	str = new char[numSize + 1];

	str[numSize] = '\0';

	for (size_t i = 0; i < numSize; i++, n /= 10) {
		str[numSize - 1 - i] = (n % 10) + '0';
	}
	size = numSize;
}

String::String()
{
	str = new char[1];
	str[0] = '\0';
	size = 0;
}

String::String(const String& other)
{
	copyFrom(other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
String::~String()
{
	free();
}


size_t String::getSize() const
{
	return size;
}
void String::concatFrom(const String& other)
{
	char* temp = new char[getSize() + other.getSize() + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
	size = size + other.getSize();
}

const char* String::c_str() const
{
	return str;
}

String& String::operator+=(const String& other)
{
	concatFrom(other);
	return *this;
}

String operator+(const String& lhs, const String& rhs)
{
	String copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}

std::ostream& operator<<(std::ostream& stream, const String& str)
{
	stream << str.str;
	return stream;
}

std::istream& operator>>(std::istream& stream, String& string)
{
	delete[] string.str;
	char buff[1024];
	stream >> std::setw(1024) >> buff;

	string.size = strlen(buff);
	string.str = new char[string.size + 1];
	strcpy(string.str, buff);

	return stream;
}

bool operator==(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;

}
bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;

}

String::String(String&& otherString)
{
	str = otherString.str;
	size = otherString.size;
	otherString.str = nullptr;
}

String& String::operator=(String&& otherString)
{

	if (this != &otherString)
	{
		free();
		str = otherString.str;
		otherString.str = nullptr;
		size = otherString.size;
	}
	return *this;
}

unsigned int numLength(int num) {
    unsigned int length = 0;
    while (num != 0) {
        ++length;
        num /= 10;
    }

    return length;
}

void absolute(int &num) {
    if(num < 0) {
        num = -num;
    }
}

String toString(int num) {
	bool isNegative = num < 0;
    absolute(num);
    int length = numLength(num) + 1; // for '\0'

    if (isNegative) {
        ++length; // for '-'
    }

    char *str = new char[length];

    str[length - 1] = '\0';
    for (int i = length - 2; num > 0; --i) {
        str[i] = num % 10 + '0';
        num /= 10;
    }

    if (isNegative) {
        str[0] = '-';
    }

    return String(str);
}

#define MULT 100
String toString(const double num) {
	int natural = (int) num;
    int real = (num - (double) natural) * MULT;

    if (real == 0) {
        return toString(natural);
    }

    bool isNegative = natural < 0;

    absolute(natural);
    absolute(real);

    unsigned int naturalLength = numLength(natural);
    unsigned int realLength = numLength(real);
    int length = naturalLength + realLength + 2; // for '.' and '\0'

    if (isNegative) {
        ++length; // for '-', '.' and '\0'
    }

    char *str = new char[length]; 

    str[length - 1] = '\0';
    for (int i = length - 2; i >= length - realLength - 1; --i) {
        str[i] = real % 10 + '0';
        real /= 10;
    }

    str[length - realLength - 2] = '.';
    for (int i = length - realLength - 3; natural > 0; --i) {
        str[i] = natural % 10 + '0';
        natural /= 10;
    }

    if (isNegative) {
        str[0] = '-';
    }

    return String(str);
}