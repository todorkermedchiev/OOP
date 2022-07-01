#pragma once

#include <cstring>
#include <exception>

class User {
private:
	char* username;
	char* email;

	void copyFrom(const User &other);
	void free();

protected:
	double balance;

public:
	User(const char* username = "", const char* email = "", double balance = 0);
	User(const User& other);
	const User& operator=(const User& other);
	~User();

	void setUsername(const char* username);
	void setEmail(const char* email);
	void setBalance(double balance);

	const char* getUsername() const;
	const char* getEmail() const;
	double getBalance() const;

	void depositMoney(double amount);
};

void User::copyFrom(const User& other) {
	this->username = nullptr;
	setUsername(other.username);
	this->email = nullptr;
	setEmail(other.email);
	setBalance(other.balance);
}

void User::free() {
	delete[] username;
	delete[] email;
	username = nullptr;
	email = nullptr;
}

User::User(const char* username, const char* email, double balance) {
	this->username = nullptr;
	setUsername(username);
	this->email = nullptr;
	setEmail(email);
	setBalance(balance);
}

User::User(const User& other) {
	copyFrom(other);
}

const User& User::operator=(const User& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

User::~User() {
	free();
}

void User::setUsername(const char* username) {
	if (username == nullptr) {
		// Exception
	}
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void User::setEmail(const char* email) {
	if (email == nullptr) {
		// Exc
	}
	delete[] this->email;
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}

void User::setBalance(double balance) {
	if (balance < 0) {
		// throw std::invalid_argument();
	}
	this->balance = balance;
}

const char* User::getUsername() const {
	return username;
}

const char* User::getEmail() const {
	return email;
}

double User::getBalance() const {
	return balance;
}

void User::depositMoney(double amount) {
	if (amount < 0) {
		// throw std::invalid_argument_exception();
	}
	balance += amount;
}