#pragma once

#define TAX 42

#include <cstring>
#include <stdexcept>
#include "user.hpp"

class PremiumUser : public User {
private:
	char* bankAccountIBAN;
	long long subscriptionTimestamp;

	void copyFrom(const PremiumUser& other);
	void free();

public:
	PremiumUser(
		const char* username = "",
		const char* email = "",
		double balance = 0,
		const char* IBAN = "",
		long long subscriptionTimestamp = 0
	);
	PremiumUser(const PremiumUser& other);
	const PremiumUser& operator=(const PremiumUser& other);
	~PremiumUser();

	void setIBAN(const char* IBAN);
	void withdrawMoney(double amount);
	void chargeForSubscription();
};

void PremiumUser::copyFrom(const PremiumUser& other) {
	this->bankAccountIBAN = nullptr;
	setIBAN(other.bankAccountIBAN);
	this->subscriptionTimestamp = other.subscriptionTimestamp;
}

void PremiumUser::free() {
	delete[] bankAccountIBAN;
	bankAccountIBAN = nullptr;
}

PremiumUser::PremiumUser(
	const char* username,
	const char* email,
	double balance,
	const char* IBAN,
	long long subscriptionTimestamp
) : User(username, email, balance) {
	this->bankAccountIBAN = nullptr;
	setIBAN(IBAN);
	this->subscriptionTimestamp = subscriptionTimestamp;
}

PremiumUser::PremiumUser(const PremiumUser& other) : User(other) {
	copyFrom(other);
}

const PremiumUser& PremiumUser::operator=(const PremiumUser& other) {
	if (this != &other) {
		User::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

PremiumUser::~PremiumUser() {
	free();
}

void PremiumUser::setIBAN(const char* IBAN) {
	delete[] this->bankAccountIBAN;
	this->bankAccountIBAN = new char[strlen(IBAN) + 1];
	strcpy(this->bankAccountIBAN, bankAccountIBAN);
}

void PremiumUser::withdrawMoney(double amount) {
	if (balance < amount) {
		throw std::invalid_argument("The amount is greater than the balance!");
	}
	balance -= amount;
}

void PremiumUser::chargeForSubscription() {
	if (balance < TAX) {
		throw std::invalid_argument("The tax is greater than the balance!");
	}
	balance -= TAX;
}