#ifndef LIST_HPP
#define LIST_HPP
#define NAME_SIZE 64
#define INITIAL_CAPACITY 256

#include <iostream>

typedef unsigned long long ull;

enum Priority {
    LOW,
    MEDIUM,
    HIGH,
    URGENT
};

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

    friend std::ostream &operator<<(const std::ostream &out, const Task &task);

    const char *getName() const;
    Priority getPriority() const;
    const Label &getLabel() const;
    bool getIsDone() const;

    void setIsDone(bool isFinished);
};

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

#endif // LIST_HPP