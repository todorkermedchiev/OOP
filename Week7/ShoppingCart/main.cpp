#include <iostream>
#include "cart.hpp"
#include "item.hpp"

using namespace std;

int main() {
    ShoppingCart cart;

    Item item1("kashkaval", 23, 11.50);
    Item item2("sirene", 21, 9.25);
    Item item3("mlqko", 12, 1.25);
    Item item4("voda", 10, 4.25);
    // Item item5("mlqko", 5, 45.5);

    // cart.addItem(item1);
    // cart.addItem(item2);
    // cart.addItem(item3);
    // cart.addItem(item4);
    // cart.addItem(item5);

    // cart.removeItem("kashkaval");

    // cout << cart.totalPrice() << endl;

    // // cart.sortByName();

    item1 = item2 = item3;
    cout << item1.getName() << ", " << item2.getName() << ", " << item3.getName() << endl;
    item1.setName("jaja");
    cout << item1.getName() << ", " << item2.getName() << ", " << item3.getName() << endl;

    // cart.save("data.txt");

    return 0;
}