#include "cart.hpp"
#include "item.hpp"
#include <cstring>
#include <iostream>
#include <fstream>

#define INTIAL_CAPACITY 32
#define RESIZE_FACTOR 2.0

using namespace std;

void ShoppingCart::free() {
    delete[] cart;
    cart = nullptr;
    // itemsCount = 0;
    // capacity = 0;
}

void ShoppingCart::copyFrom(const ShoppingCart &other) {
    free();
    capacity = other.capacity;
    itemsCount = other.itemsCount;
    cart = new Item[capacity];

    for (int i = 0; i < itemsCount; ++i) {
        cart[i] = other.cart[i];
    }
}

void ShoppingCart::resize(const double resizeFactor) {
    unsigned int newCapacity = capacity * resizeFactor;
    Item *newCart = new Item[newCapacity];
    for (int i = 0; i < itemsCount; ++i) {
        newCart[i] = cart[i];
    }

    delete[] cart;
    capacity = newCapacity;
    cart = newCart;
}

int ShoppingCart::find(const char *name) const {
    for (int i = 0; i < itemsCount; ++i) {
        if (strcmp(cart[i].getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

ShoppingCart::ShoppingCart() {
    cart = new Item[INTIAL_CAPACITY];
    itemsCount = 0;
    capacity = INTIAL_CAPACITY;
}

ShoppingCart::ShoppingCart(unsigned int capacity) {
    cart = new Item[capacity];
    itemsCount = 0;
    capacity = capacity;
}

ShoppingCart::ShoppingCart(const ShoppingCart &other) {
    copyFrom(other);
}

ShoppingCart &ShoppingCart::operator=(const ShoppingCart &other) {
    copyFrom(other);
    return *this;
}

ShoppingCart::~ShoppingCart() {
    free();
}

void ShoppingCart::addItem(const Item &newItem) {
    if (find(newItem.getName()) != -1) {
        cout << "The item is already in the cart!\n";
        return;
    }

    if (itemsCount >= capacity) {
        resize(RESIZE_FACTOR);
    }

    cart[itemsCount++] = newItem;
    cout << "Item added successfully!\n";
}

void ShoppingCart::removeItem(const char *name) {
    int index = find(name);
    if (index == -1) {
        cout << "This item is not in the cart!\n";
        return;
    }

    for (int i = index; i < itemsCount - 1; ++i) {
        cart[i] = cart[i + 1];
    }

    --itemsCount;
    cout << "Item successfully removed\n";

    if (itemsCount <= capacity / 4) {
        resize(1.0 / RESIZE_FACTOR);
    }
}

unsigned int ShoppingCart::getItemsCount() const {
    return itemsCount;
}

unsigned int ShoppingCart::getCapacity() const {
    return capacity;
}

bool ShoppingCart::exists(const char *name) const {
    return find(name) != -1;
}

bool ShoppingCart::isEmpty() const {
    return itemsCount == 0;
}

double ShoppingCart::getPriceOf(const char *name) const {
    int index = find(name);
    if (index == -1) {
        return 0.0; 
    }

    return cart[index].getPrice();
}

double ShoppingCart::totalPrice() const {
    double total = 0.0;
    for (int i = 0; i < itemsCount; ++i) {
        total += cart[i].getPrice();
    }

    return total;
}

void ShoppingCart::sortByName() {
    int minIndex = 0;
    for (int i = 0; i < itemsCount; ++i) {
        minIndex = i;
        for (int j = i + 1; j < itemsCount; ++j) {
            if (strcmp(cart[minIndex].getName(), cart[j].getName()) > 0) {
                minIndex = j;
            }
        }
        if (strcmp(cart[i].getName(), cart[minIndex].getName()) > 0) {
            swap(cart[i], cart[minIndex]);
        }
    }
}

void ShoppingCart::swap(Item &item1, Item &item2) {
    Item tmp = item1;
    item1 = item2;
    item2 = tmp;
}

void ShoppingCart::save(const char *path) const {
    ofstream file(path);
    if (!file.is_open()) {
        return;
    }

    for (int i = 0; i < itemsCount; ++i) {
        file << cart[i].getName() << ", "
             << cart[i].getPrice() << ", "
             << cart[i].getAmount() << "\n";
    }

    file.close();
}
