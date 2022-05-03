#include <iostream>
#include "task2.hpp"

// using namespace std;

int main() {
    // int a = 4;
    // int b = 8;

    // std::cout << a << ' ' << b << std::endl;
    // swap(a, b);
    // std::cout << a << ' ' << b << std::endl;
    // std::cout << max(a, b) << std::endl;
    // std::cout << min(a, b) << std::endl;


    Pair<int, double> p(2, 3.4);
    Pair<double, int> d = p.swapped();
    d.print();

    return 0;
}