#pragma once
#define INITIAL_CAPACITY 64
#define RESIZE_FACTOR 2

#include "namedObject.hpp"
#include <iostream>

template <typename T>
class NamedObjectArray {
private:
    NamedObject<T> *array;
    unsigned int capacity;
    int objectsCount;

    void allocate(unsigned int capacity);
    void free();
    void copyFrom(const NamedObjectArray &other);
    void resize();

public:
    NamedObjectArray();
    NamedObjectArray(int capacity);
    NamedObjectArray(const NamedObjectArray &other);
    const NamedObjectArray &operator=(const NamedObjectArray &other);
    ~NamedObjectArray();

    int getObjectsCount() const;
    void addObject(const char *name, const T &object);
    T &operator[](int index) const;
};

template <typename T>
void NamedObjectArray<T>::allocate(unsigned int capacity) {
    objectsCount = 0;
    this->capacity = capacity;
    array = new NamedObject<T>[capacity];
}

template <typename T>
void NamedObjectArray<T>::free() {
    delete[] array;
    array = nullptr;
}

template <typename T>
void NamedObjectArray<T>::copyFrom(const NamedObjectArray<T> &other) {
    allocate(other.capacity);
    this->objectsCount = other.objectsCount;
    for (int i = 0; i < objectsCount; ++i) {
        this->array[i] = other.array[i];
    }
}

template <typename T>
void NamedObjectArray<T>::resize() {
    capacity *= RESIZE_FACTOR;
    NamedObject<T> *newArray = new NamedObject<T>[capacity];
    for (int i = 0; i < objectsCount; ++i) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

template <typename T>
NamedObjectArray<T>::NamedObjectArray() {
    allocate(INITIAL_CAPACITY);
}

template <typename T>
NamedObjectArray<T>::NamedObjectArray(int capacity) {
    allocate(capacity);
}

template <typename T>
NamedObjectArray<T>::NamedObjectArray(const NamedObjectArray<T> &other) {
    copyFrom(other);
}

template <typename T>
const NamedObjectArray<T> &NamedObjectArray<T>::operator=(const NamedObjectArray<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
NamedObjectArray<T>::~NamedObjectArray() {
    free();
}

template <typename T>
int NamedObjectArray<T>::getObjectsCount() const {
    return objectsCount;
}

template <typename T>
void NamedObjectArray<T>::addObject(const char *name, const T &object) {
    if (objectsCount == capacity) {
        resize();
    }
    array[objectsCount] = NamedObject(name, object);
    ++objectsCount;
}

template <typename T>
T &NamedObjectArray<T>::operator[](int index) const {
    // Invalid index...
    try {
        if (index >= 0 || index < objectsCount) {
            return array[index];
        }
        else {
            throw ("out_of_range");
        }
    }
    catch (const char *except) {
        std::cout << "The index must be between 0 and " << objectsCount - 1 << std::endl;
        std::cout << except << std::endl;
    }
}
