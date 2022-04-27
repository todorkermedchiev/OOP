#ifndef PROJECT_HPP
#define PROJECT_HPP
#define INITIAL_CAPACITY 256

#include <iostream>
#include "task.hpp"

class Project
{
private:
    Task *tasks;
    unsigned int capacity;
    unsigned int fillSize;

    void free();
    void resize();
    unsigned int find(const char *name) const;
    void swapTasks(Task &task1, Task &task2);
    void sortByName();

public:
    Project(unsigned int capacity = INITIAL_CAPACITY);
    ~Project();

    void add(const Task &newTask);
    void finish(const char* name);
    void printUnfinished() const;
    void printFinished() const;
    void printByLabel(const char *labelName) const;
    void clear();
    int getFinishedCount() const;
    int getUnfinishedCount() const;

    friend std::ostream &operator<<(std::ostream &out, const Project &project);
};

#endif // PROJECT_HPP