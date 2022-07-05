#include "student.hpp"
#include <cstring>
#include <iostream>

using namespace std;

Student::Student() {
    name = nullptr;
    setName("");
    setFn(0);
    setAge(0);
    setFriend(nullptr);
    setMajor(SI);
}

Student::Student(
    const char *name,
    unsigned int fn,
    unsigned short age,
    Student *bestFriend,
    Major major
) {
    this->name = nullptr;
    setName(name);
    setFn(fn);
    setAge(age);
    setFriend(bestFriend);
    setMajor(major);
}

Student::Student(const Student &other) {
    name = nullptr;
    setName(other.getName());
    setFn(other.getFn());
    setAge(other.getAge());
    setFriend(other.getFriend());
    setMajor(other.getMajor());
}

Student &Student::operator=(const Student &other) {
    if (this == &other) {
        return *this;
    }
    setName(other.getName());
    setFn(other.getFn());
    setAge(other.getAge());
    setFriend(other.getFriend());
    setMajor(other.getMajor());
    return *this;
}

Student::~Student() {
    delete[] name;
    name = nullptr;
    bestFriend = nullptr;
}

void Student::setName(const char *name) {
    delete[] this->name;
    int length = strlen(name);
    this->name = new char[length + 1];
    strcpy(this->name, name);
}

void Student::setFn(unsigned int fn) {
    this->fn = fn;
}

void Student::setAge(unsigned short age) {
    this->age = age;
}

void Student::setFriend(Student *bestFriend) {
    this->bestFriend = bestFriend;
}

void Student::setMajor(Major major) {
    this->major = major;
}

const char *Student::getName() const {
    return name;
}

unsigned int Student::getFn() const {
    return fn;
}

unsigned short Student::getAge() const {
    return age;
}

Student *Student::getFriend() const {
    return bestFriend;
}

Major Student::getMajor() const {
    return major;
}

void Student::print() const {
    cout << "Name: " << name << endl;
    cout << "Fn: " << fn << endl;
    cout << "Age: " << age << endl;
    cout << "Best friend: ";
    cout << (bestFriend == nullptr ? "NULL" : bestFriend->getName()) << endl;
    cout << "Major: ";
    switch (major)
    {
    case SI:
        cout << "Softuerno inzhinerstvo";
        break;
    case KN:
        cout << "Kompyutarni nauki";
        break;
    case I:
        cout << "Informatika";
        break;
    case M:
        cout << "Matematika";
        break;
    default:
        cout << "Undefined";
        break;
    }

    cout << endl << "--------------------" << endl;
}
