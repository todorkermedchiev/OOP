#ifndef LABEL_HPP
#define LABEL_HPP
#define NAME_SIZE 64

typedef unsigned long long ull;

class Label
{
private:
    ull id;
    char name[NAME_SIZE];

    void copyFrom(const Label &other);

public:
    Label(ull id = 0, const char *name = "");
    Label(const Label& other);
    Label &operator=(const Label &other);

    const char *getName() const;
};

#endif // LABEL_HPP