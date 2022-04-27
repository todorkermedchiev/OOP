#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include "label.hpp"

enum Priority {
    LOW,
    MEDIUM,
    HIGH,
    URGENT
};

class Task {
private:
    char *name;
    Priority priority;
    Label label;
    bool done;

    void copyName(const char *name);
    void copyFrom(const Task &other);
    void free();

public:
    Task();
    Task(const char *name, Priority priority, const Label &label, bool done);

    friend std::ostream &operator<<(std::ostream &out, const Task &task);

    const char *getName() const;
    Priority getPriority() const;
    const Label &getLabel() const;
    bool getIsDone() const;

    void setIsDone(bool isFinished);
};

#endif // TASK_HPP
