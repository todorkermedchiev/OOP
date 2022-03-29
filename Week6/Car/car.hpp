#ifndef CAR_HPP
#define CAR_HPP

class Car {
private:
    char *name;
    unsigned int year;

    void copyName(const char *name);
    void copyFrom(const Car &other);
    void free();

public:
    Car();
    Car(const char *name, unsigned int year);
    Car(const Car &other);
    Car& operator=(const Car &other);
    ~Car();

    const char* getName() const;
    unsigned int getYear() const;

    void setName(const char *name);
    void setYear(unsigned int year);
};

#endif // CAR_HPP