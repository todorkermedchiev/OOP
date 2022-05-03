#pragma once

#include <iostream>

template <typename T, typename V>
class Pair {
private:
    const T first;
    const V second;

public:
    Pair(T first = 0, V second = 0);

    Pair<V, T> swapped() const;

    void print() const;
    T getFirst() const;
    V getSecond() const;
};

template <typename T, typename V>
Pair<T, V>::Pair(T first, V second) : first(first), second(second) {}

template <typename T, typename V>
Pair<V, T> Pair<T, V>::swapped() const {
    Pair<V, T> newPair(second, first);
    return newPair;
}

template <typename T, typename V>
void Pair<T, V>::print() const {
    std::cout << first << " " << second << '\n';
}

template <typename T, typename V>
T Pair<T, V>::getFirst() const {
    return first;
}

template <typename T, typename V>
V Pair<T, V>::getSecond() const {
    return second;
}