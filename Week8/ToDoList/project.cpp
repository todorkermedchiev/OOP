#include "project.hpp"
#include <iostream>
#include <cstring>

#define RESIZE_FACTOR 2

using namespace std;

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