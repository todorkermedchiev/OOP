#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
private:
    int *data;
    unsigned int elementsCount;
    unsigned int capacity;

    void allocate(unsigned int initSize);
    void resize(int diff);

public:
    Vector();
    Vector(unsigned int initSize);

    int at(unsigned int index) const;
    int front() const;
    int back() const;
    bool empty() const;
    int size() const;
    void clear();
    void insert(unsigned int index, int element);
    void push_back(int element);
    void pop_back();

    ~Vector();
};


#endif // VECTOR_HPP