#include "namedObject.hpp"
#include "namedObjectArray.hpp"

int main() {
    int obj = 5;
    NamedObjectArray<int> arr;
    arr.addObject("five", obj);

    return 0;
}