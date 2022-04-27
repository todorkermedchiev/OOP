#include "list.hpp"
#include <cstring>
#include <iostream>
#define RESIZE_FACTOR 2

using namespace std;

// Label
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

// Task
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

// Project
void Project::free() {
    delete[] tasks;
    tasks = nullptr;
    capacity = 0;
    fillSize = 0;
}

void Project::resize() {
    Task *newTasks = new Task[capacity * RESIZE_FACTOR];
    for (int i = 0; i < fillSize; ++i) {
        newTasks[i] = tasks[i];
    }
    delete[] tasks;
    capacity *= RESIZE_FACTOR;
    tasks = newTasks;
}

unsigned int Project::find(const char *name) const {
    int index = 0;
    while (index < fillSize) {
        if (strcmp(tasks[index].getName(), name) == 0) {
            return index;
        }
        ++index;
    }
    return -1;
}

void Project::swapTasks(Task &task1, Task &task2) {
    Task tmp = task1;
    task1 = task2;
    task2 = tmp;
}

void Project::sortByName() {
    unsigned int maxIndex = 0;
    for (int i = 0; i < fillSize; ++i) {
        maxIndex = i;
        for (int j = i + 1; j < fillSize; ++j) {
            if (strcmp(tasks[i].getName(), tasks[j].getName()) > 0) { //?
                maxIndex = j;
            }
        }
        if (strcmp(tasks[i].getName(), tasks[maxIndex].getName()) > 0) { //?
            swapTasks(tasks[i], tasks[maxIndex]);
        }
    }
}

Project::Project(unsigned int capacity) {
    tasks = new Task[capacity];
    this->capacity = capacity;
    this->fillSize = 0;
}

void Project::add(const Task &newTask) {
    for (int i = 0; i < fillSize; ++i) {
        if (strcmp(tasks[i].getName(), newTask.getName()) == 0) {
            return;
        }
    }

    if (fillSize >= capacity) {
        resize();
    }

    tasks[fillSize] = newTask;
    ++fillSize;
    sortByName();
}

void Project::finish(const char* name) {
    int index = find(name);
    if (index == -1) {
        return;
    }
    tasks[index].setIsDone(true);
}

void Project::printUnfinished() const {
    for (int i = 0; i < fillSize; ++i) {
        if (!tasks[i].getIsDone() && tasks[i].getPriority() == URGENT) {
            cout << tasks[i];
        }
    }
    for (int i = 0; i < fillSize; ++i) {
        if (!tasks[i].getIsDone() && tasks[i].getPriority() == HIGH) {
            cout << tasks[i];
        }
    }
    for (int i = 0; i < fillSize; ++i) {
        if (!tasks[i].getIsDone() && tasks[i].getPriority() == MEDIUM) {
            cout << tasks[i];
        }
    }
    for (int i = 0; i < fillSize; ++i) {
        if (!tasks[i].getIsDone() && tasks[i].getPriority() == LOW) {
            cout << tasks[i];
        }
    }
}

void Project::printFinished() const {
    for (int i = 0; i < fillSize; ++i) {
        if (tasks[i].getIsDone()) {
            cout << tasks[i];
        }
    }
}

void Project::printByLabel(const char *labelName) const {
    cout << "#### Label: \'" << labelName << "\'\n\n";
    cout << "### Unfinished\n\n";

    for (int i = 0; i < fillSize; ++i) {
        if (strcmp(tasks[i].getLabel().getName(), labelName) == 0 && !tasks[i].getIsDone()) {
            cout << tasks[i];
        }
    }

    cout << endl;
    cout << "### Finished\n\n";
    
    for (int i = 0; i < fillSize; ++i) {
        if (strcmp(tasks[i].getLabel().getName(), labelName) == 0 && tasks[i].getIsDone()) {
            cout << tasks[i];
        }
    }
}

void Project::clear() {
    fillSize = 0;
}

int Project::getFinishedCount() const {
    int counter = 0;
    for (int i = 0; i < fillSize; ++i) {
        if (tasks[i].getIsDone()) {
            ++counter;
        }
    }
    return counter;
}

int Project::getUnfinishedCount() const {
    int counter = 0;
    for (int i = 0; i < fillSize; ++i) {
        if (!tasks[i].getIsDone()) {
            ++counter;
        }
    }
    return counter;
}

Project::~Project() {
    free();
}

ostream &operator<<(ostream &out, const Project &project) {
    out << "### Unfinished\n\n";
    out << project.getUnfinishedCount() << " tasks:\n";
    project.printUnfinished();
    out << endl;
    out << "### Finished\n\n";
    out << project.getFinishedCount() << " tasks:\n";
    project.printFinished();
    return out;
}