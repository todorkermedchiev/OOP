#pragma once
#include <cstring>

template <typename T>
class NamedObject {
private:
    unsigned int id;
    T object;
    char *name;

    static unsigned int idCounter;

    void copyFrom(const NamedObject &other);
    void move(NamedObject &&other);
    void free();

public:
    NamedObject();
    NamedObject(const char *name, const T &object);
    NamedObject(const NamedObject &other);
    const NamedObject &operator=(const NamedObject &other);
    NamedObject(NamedObject &&other);
    const NamedObject &operator=(NamedObject &&other);
    ~NamedObject();

    unsigned int getId() const;
    const T &getObject() const;
    const char *getName() const;

};

template <typename T>
unsigned int NamedObject<T>::idCounter = 1;

template <typename T>
NamedObject<T>::NamedObject() {
    // id = 0;
    name = nullptr;
}

template <typename T>
NamedObject<T>::NamedObject(const char *name, const T &object) {
    this->id = idCounter;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->object = object;
    ++idCounter;
}

template <typename T>
void NamedObject<T>::copyFrom(const NamedObject<T> &other) {
    this->id = idCounter;
    this->name = new char[strlen(other.name)];
    strcpy(this->name, other.name);
    this->object = other.object;
    ++idCounter;
}

template <typename T>
void NamedObject<T>::move(NamedObject<T> &&other) {
    id = other.id;
    object = other.object;
    name = other.name;
    other.name = nullptr;
}

template <typename T>
void NamedObject<T>::free() {
    delete[] name;
}

template <typename T>
NamedObject<T>::NamedObject(const NamedObject<T> &other) {
    copyFrom(other);
}

template <typename T>
const NamedObject<T> &NamedObject<T>::operator=(const NamedObject<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
NamedObject<T>::NamedObject(NamedObject<T> &&other) {
    move(other);
}

template <typename T>
const NamedObject<T> &NamedObject<T>::operator=(NamedObject<T> &&other) {
    if (this != &other) {
        free();
        // move(other); // ????
        id = other.id;
        object = other.object;
        name = other.name;
        other.name = nullptr;
    }

    return *this;
}

template <typename T>
NamedObject<T>::~NamedObject() {
    free();
}

template <typename T>
unsigned int NamedObject<T>::getId() const {
    return id;
}

template <typename T>
const T &NamedObject<T>::getObject() const {
    return object;
}

template <typename T>
const char *NamedObject<T>::getName() const {
    return name;
}
