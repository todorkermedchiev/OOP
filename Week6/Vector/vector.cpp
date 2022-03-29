#include "vector.hpp"

#define INIT_SIZE 10

void Vector::allocate(unsigned int initSize) {
    data = new int[initSize]{};
    capacity = initSize;
    elementsCount = 0;
}

void Vector::resize(int diff) {
    int *newData = new int[capacity + diff]{};
    for (int i = 0; i < elementsCount; ++i) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    capacity = capacity + diff;
}

Vector::Vector() {
    allocate(INIT_SIZE);
}

Vector::Vector(unsigned int initSize) {
    allocate(initSize);
}

bool Vector::empty() const {
    return elementsCount == 0;
}

int Vector::at(unsigned int index) const {
    if (index < 0 || index >= elementsCount) {
        return 0;
    }

    return data[index];
}

int Vector::front() const {
    if (empty()) {
        return 0;
    }

    return data[0];
}

int Vector::back() const {
    if (empty()) {
        return 0;
    }

    return data[elementsCount - 1];
}

int Vector::size() const {
    return elementsCount;
}

void Vector::clear() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    elementsCount = 0;
}

void Vector::insert(unsigned int index, int element) {
    if (index < 0 || index > elementsCount) {
        return;
    }

    if (elementsCount >= capacity) {
        resize(INIT_SIZE);
    }

    for (int i = elementsCount; i > index; --i) {
        data[i] = data[i - 1];
    }

    data[index] = element;
    ++elementsCount;
}

void Vector::push_back(int element) {
    insert(elementsCount, element);
}

void Vector::pop_back() {
    data[elementsCount - 1] = 0;
    --elementsCount;

    if (elementsCount <= capacity - INIT_SIZE) {
        resize(-INIT_SIZE);
    }
}

Vector::~Vector() {
    clear();
}
