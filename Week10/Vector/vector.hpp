#ifndef VECTOR_HPP
#define VECTOR_HPP
#define INIT_SIZE 10

#include <iostream>

template <typename T>
class Vector;

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &vec);

template <typename T>
class Vector {
private:
    T *data;
    unsigned int elementsCount;
    unsigned int capacity;

    void allocate(unsigned int initSize);
    void resize(int diff);

public:
    Vector();
    Vector(unsigned int initSize);

    T at(unsigned int index) const;
    T front() const;
    T back() const;
    bool empty() const;
    int size() const;
    void clear();
    void insert(unsigned int index, T element);
    void push_back(T element);
    void pop_back();

    friend std::ostream &operator<< <> (std::ostream &out, const Vector &vec);
    // {
    //     for (int i = 0; i < vec.elementsCount; ++i) {
    //     out << vec.data[i] << ' ';
    //     }
    //     out << '\n';
    //     return out;
    // }

    ~Vector();
};

template <typename T>
void Vector<T>::allocate(unsigned int initSize) {
    data = new int[initSize]{};
    capacity = initSize;
    elementsCount = 0;
}

template <typename T>
void Vector<T>::resize(int diff) {
    T *newData = new T[capacity + diff]{};
    for (int i = 0; i < elementsCount; ++i) {
        newData[i] = data[i];
    }
    
    delete[] data;
    data = newData;
    capacity = capacity + diff;
}

template <typename T>
Vector<T>::Vector() {
    allocate(INIT_SIZE);
}

template <typename T>
Vector<T>::Vector(unsigned int initSize) {
    allocate(initSize);
}

template <typename T>
bool Vector<T>::empty() const {
    return elementsCount == 0;
}

template <typename T>
T Vector<T>::at(unsigned int index) const {
    if (index < 0 || index >= elementsCount) {
        return 0;
    }

    return data[index];
}

template <typename T>
T Vector<T>::front() const {
    if (empty()) {
        return 0;
    }

    return data[0];
}

template <typename T>
T Vector<T>::back() const {
    if (empty()) {
        return 0;
    }

    return data[elementsCount - 1];
}

template <typename T>
int Vector<T>::size() const {
    return elementsCount;
}

template <typename T>
void Vector<T>::clear() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    elementsCount = 0;
}

template <typename T>
void Vector<T>::insert(unsigned int index, T element) {
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

template <typename T>
void Vector<T>::push_back(T element) {
    insert(elementsCount, element);
}

template <typename T>
void Vector<T>::pop_back() {
    data[elementsCount - 1] = 0;
    --elementsCount;

    if (elementsCount <= capacity - INIT_SIZE) {
        resize(-INIT_SIZE);
    }
}

template <typename T>
Vector<T>::~Vector() {
    clear();
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Vector<T> &vec) {
    for (int i = 0; i < vec.elementsCount; ++i) {
        out << vec.data[i] << ' ';
    }
    out << '\n';
    return out;
}

#endif // VECTOR_HPP