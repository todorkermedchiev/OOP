#include <iostream>
#include "timestamp.hpp"

using namespace std;

int main() {
    Timestamp time(23, 59, 59);
    /*long seconds = 0;
    cin >> seconds;
    time.secondsToTime(seconds);*/

    // time.setMinutes(15);
    // time.addSeconds(65);
    // time.addMinutes(12);
    // cout << time.getHours() << endl;
    time.print();
}