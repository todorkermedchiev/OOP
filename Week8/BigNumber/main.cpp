#include <iostream>
#include "bigNumber.hpp"

using namespace std;

int main() {
    BigNumber a("1363541356");
    BigNumber b("1536874354");
    BigNumber c = a + b;
    BigNumber d = a - b;

    d.print();


    return 0;
}