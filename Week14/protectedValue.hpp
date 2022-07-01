#pragma once
#include <stdexcept>
#include <exception>

template <typename T>
class ProtectedValue {
private:
    T value;
    unsigned int code;

public:
    ProtectedValue() {}
    ProtectedValue(const T &value, unsigned int code);
    const T &getValue(unsigned int code) const;
};

template <typename T>
ProtectedValue<T>::ProtectedValue(const T &value, unsigned int code) {
    this->value = value;
    this->code = code;
}

template <typename T>
const T &ProtectedValue<T>::getValue(unsigned int code) const {
    if (this->code != code) {
        throw std::invalid_argument("Wrong code!\n");
    }

    return value;
}