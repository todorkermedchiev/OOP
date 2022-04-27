#include "label.hpp"
#include <cstring>

void Label::copyFrom(const Label &other) {
    strcpy(name, other.name);
    id = other.id;
}

Label::Label(ull id , const char *name) {
    this->id = id;
    strcpy(this->name, name);
}

Label::Label(const Label &other) {
    copyFrom(other);
}

Label &Label::operator=(const Label &other) {
    copyFrom(other);
    return *this;
}

const char *Label::getName() const {
    return name;
}