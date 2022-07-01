#pragma once
#include "protectedValue.hpp"
#include <iostream>

#define INITIAL_CAPACITY 8
#define RESIZE_FACTOR 2

template <typename T>
class ProtectedValueArray {
private:
    ProtectedValue<T> *arr;
    unsigned int size;
    unsigned int capacity;

    void resize();
    void allocate(unsigned int capacity);
    void copyFrom(const ProtectedValueArray &other);
    void free();

public:
    ProtectedValueArray();
    ProtectedValueArray(const ProtectedValueArray &other);
    const ProtectedValueArray &operator=(const ProtectedValueArray &other);
    ~ProtectedValueArray();

    void addElement(const T &value, unsigned int code);
    const T &getElement(unsigned int index, unsigned int code);
};

template <typename T>
void ProtectedValueArray<T>::resize() {
    capacity *= RESIZE_FACTOR;
    ProtectedValue<T> *newArr = new ProtectedValue<T>[capacity];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    newArr = nullptr;
}

template <typename T>
void ProtectedValueArray<T>::allocate(unsigned int capacity) {
    this->capacity = capacity;
    this->size = 0;
    arr = new ProtectedValue<T>[capacity];
}

template <typename T>
void ProtectedValueArray<T>::copyFrom(const ProtectedValueArray<T> &other) {
    allocate(other.capacity);
    size = other.size;
    for (int i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
void ProtectedValueArray<T>::free() {
    delete[] arr;
}

template <typename T>
ProtectedValueArray<T>::ProtectedValueArray() {
    allocate(INITIAL_CAPACITY);
}

template <typename T>
ProtectedValueArray<T>::ProtectedValueArray(const ProtectedValueArray<T> &other) {
    copyFrom(other);
}

template <typename T>
const ProtectedValueArray<T> &ProtectedValueArray<T>::operator=(const ProtectedValueArray<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

template <typename T>
ProtectedValueArray<T>::~ProtectedValueArray() {
    free();
}


template <typename T>
void ProtectedValueArray<T>::addElement(const T &value, unsigned int code) {
    if (size >= capacity) {
        resize();
    }

    arr[size++] = ProtectedValue(value, code);
}

template <typename T>
const T &ProtectedValueArray<T>::getElement(unsigned int index, unsigned int code) {
    try {
        return arr[index].getValue(code);
    }
    catch(std::invalid_argument e) {
        std::cerr /*<< "Invalid code!\n"*/ << e.what();
        throw e;
    }
    catch(...) {
        std::cerr << "Unknown error!\n";
        throw std::exception();
    }
}