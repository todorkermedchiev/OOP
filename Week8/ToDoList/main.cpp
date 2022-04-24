#include <iostream>
#include "list.hpp"

using namespace std;


int main() {
    Label label1(1234, "label1");
    Label label2(4653, "label2");

    Task task1("task1", HIGH, label1, false);
    Task task2("task2", MEDIUM, label2, true);

    Project myProject;
    myProject.add(task1);
    myProject.add(task2);

    myProject.printByLabel("label1");
    myProject.finish("task1");
    myProject.printByLabel("label1");



    return 0;
}