#include "student.hpp"
#include <iostream>
using namespace std;

int main() {
    Student pesho("Pesho", 123456, 17, nullptr, SI);
    Student gosho("Gosho", 321564, 18, &pesho, KN);
    pesho.setFriend(&gosho);

    pesho.print();

    return 0;
}