#include <iostream>
#include "vector.hpp"

using namespace std;

int main() {
    Vector<int> myVec(3);
    myVec.push_back(2);
    myVec.push_back(5);
    myVec.push_back(13);
    cout << myVec;
    
    myVec.insert(1, 66);

    cout << myVec;

    myVec.pop_back();

    cout << myVec;

    // cout << myVec.front() << ' ' << myVec.back() << endl;


    return 0;
}