#pragma once

enum Major {
    SI,
    KN,
    I,
    M
};

class Student {
private:
    char *name;
    unsigned int fn;
    unsigned short age;
    Student *bestFriend;
    Major major;

public:
    Student();
    Student(
        const char *name,
        unsigned int fn,
        unsigned short age,
        Student *bestFriend,
        Major major
        );  
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    void setName(const char *name);
    void setFn(unsigned int fn);
    void setAge(unsigned short age);
    void setFriend(Student *bestFriend);
    void setMajor(Major major);

    const char *getName() const;
    unsigned int getFn() const;
    unsigned short getAge() const;
    Student *getFriend() const;
    Major getMajor() const;

    void print() const;
};