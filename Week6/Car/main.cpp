#include <iostream>
#include "car.hpp"

using namespace std;

int main() {
    Car myCar("Passat", 2000);
    Car car2(myCar);
    cout << myCar.getName() << ", " << myCar.getYear() << endl;
    cout << car2.getName() << ", " << car2.getYear() << endl;
    car2.setName("Golf");
    cout << myCar.getName() << ", " << myCar.getYear() << endl;
    cout << car2.getName() << ", " << car2.getYear() << endl;

    Car car3;
    cout << car3.getName() << ", " << car3.getYear() << endl;
    car3 = car2;
    cout << car3.getName() << ", " << car3.getYear() << endl;
    

    return 0;
}