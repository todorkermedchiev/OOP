#pragma once

template <typename T>
void swap(/*const*/ T &first, /*const*/ T &second) { // run-time error
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
T max(const T &first, const T &second) {
    return first > second ? first : second; 
}

template <typename T>
T min(const T &first, const T &second) {
    return first > second ? second : first;
}