#include <iostream>
#include "vector.hpp"

using namespace std;

int main()
{
    
    Vector3D a = {5, 97, 80};
    char path[] = "serialized.bin";
    serialize(a, path);
    Vector3D b = deserialize(path);
    cout << length(a) << endl;
    cout << length(b) << endl;
    cout << scalarProduct(a, b) << endl;
    cout << arePerpendicular(a, b) << endl;
    

    return 0;
}
