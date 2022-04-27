#include "task.hpp"
#include <cstring>
#include <iostream>

using namespace std;

void Task::free() {
    delete[] name;
    name = nullptr;
}

void Task::copyName(const char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Task::copyFrom(const Task &other) {
    free();
    copyName(other.name);
}

Task::Task() {
    copyName("");
    priority = LOW;
    done = false;
}

Task::Task(const char *name, Priority priority, const Label &label, bool done) {
    copyName(name);
    this->priority = priority;
    this->label = label;
    this->done = done;
}

ostream &operator<<(ostream &out, const Task &task) {
    out << "- " << (task.getIsDone() ? "[x]" : "[ ]") << ' ';
    out << task.getName() << ' ';
    if (!task.getIsDone()) {
        out << "(**";
        switch (task.getPriority())
        {
        case LOW:
            out << "LOW";
            break;

        case MEDIUM:
            out << "MEDIUM";
            break;

        case HIGH:
            out << "HIGH";
            break;

        case URGENT:
            out << "URGENT";
            break;
    
        default:
            break;
        }
        out << "**)";
    }
    out << endl;
    return out;
}

const char *Task::getName() const {
    return name;
}

Priority Task::getPriority() const {
    return priority;
}

const Label &Task::getLabel() const {
    return label;
}

bool Task::getIsDone() const {
    return done;
}

void Task::setIsDone(bool isFinished) {
    done = isFinished;
}
