#include <iostream>
#include "timestamp.hpp"

using namespace std;

int main() {
    Timestamp time(23, 59, 59);

    time.setMinutes(15);
    time.addSeconds(65);
    time.addMinutes(12);
    cout << time.getHours() << endl;
    time.print();

    return 0;
}