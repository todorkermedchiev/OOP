#pragma once

#include <fstream>
class String
{
	char* str;
	size_t size;

	void copyFrom(const String& other);
	void free();

	void concatFrom(const String& other);

public:
	String();
	String(const char*);
	String(size_t n); //convert constructor

	String(const String&);

	String(String&&); //move constructor that accepts rvalue;

	String& operator=(const String& other);
	String& operator=(String&& other);  //move op= that accepts rvalue;

	~String();

	size_t getSize() const;

	const char* c_str() const;

	String& operator+=(const String& other);

	friend std::ostream& operator<<(std::ostream& stream, const String& str);
	friend std::istream& operator>>(std::istream& stream, String& str);

};

String operator+(const String& lhs, const String& rhs);

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);

String toString(int num);
String toString(const double num);