#include "protectedValueArray.hpp"
#include <iostream>

int main() {
    ProtectedValueArray<int> arr;
    arr.addElement(21, 2);
    std::cout << arr.getElement(0, 2);

    return 0;
}