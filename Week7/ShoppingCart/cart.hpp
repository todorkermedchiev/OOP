#ifndef SHOPPING_CART_HPP
#define SHOPPING_CART_HPP
#include "item.hpp"

class ShoppingCart {
private:
    Item *cart;
    unsigned int itemsCount;
    unsigned int capacity;

    void free();
    void copyFrom(const ShoppingCart &other);
    void resize(const double resizeFactor);
    int find(const char *name) const;

    void swap(Item &item1, Item &item2);
public:
    ShoppingCart();
    ShoppingCart(unsigned int capacity);
    ShoppingCart(const ShoppingCart &other);
    ShoppingCart &operator=(const ShoppingCart &other);
    ~ShoppingCart();

    unsigned int getItemsCount() const;
    unsigned int getCapacity() const;

    void addItem(const Item &newItem);
    void removeItem(const char *name);
    bool exists(const char *name) const;
    bool isEmpty() const;
    double getPriceOf(const char *name) const;
    double totalPrice() const;
    void sortByName();
    void save(const char *path) const;
};

#endif // SHOPPING_CART_HPP