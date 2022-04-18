#include <iostream>
#include "bigNumber.hpp"

using namespace std;

int main() {
    BigNumber a("123456789");
    BigNumber b("654986532416");
    BigNumber c = a + b;

    c.print();


    return 0;
}