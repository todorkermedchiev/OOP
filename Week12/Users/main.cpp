#include "user.hpp"
#include "premiumUser.hpp"
#include <iostream>

using namespace std;

int main() {
	PremiumUser user("username", "email", 45.23, "adesfg", 156);
	cout << user.getUsername() << endl;
	cout << user.getBalance() << endl;

	return 0;
}