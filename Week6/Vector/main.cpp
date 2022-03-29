#include <iostream>
#include "vector.hpp"

using namespace std;

int main() {
    Vector myVec(3);
    myVec.push_back(2);
    myVec.push_back(5);
    myVec.push_back(13);
    
    myVec.insert(1, 66);
    
    myVec.pop_back();
    cout << myVec.front() << ' ' << myVec.back() << endl;

    for (int i = 0; i < myVec.size(); ++i) {
        cout << myVec.at(i) << ' ';
    }

    return 0;
}