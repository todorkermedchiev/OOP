#include <iostream>
#include "list.hpp"

using namespace std;


int main() {
    Label label1(1234, "label1");
    Label label2(4653, "label2");
    Label label3(4653, "label3");
    
    Task task1("task1", HIGH, label1, false);
    Task task2("task2", MEDIUM, label2, true);
    Task task3("task3", URGENT, label3, false);
    Task task4("task4", MEDIUM, label1, true);
    Task task5("task5", LOW, label2, false);
    Task task6("task6", HIGH, label3, true);
    Task task7("task7", MEDIUM, label1, false);
    Task task8("task8", URGENT, label2, true);
    Task task9("task9", LOW, label3, false);

    Project myProject;
    myProject.add(task1);
    myProject.add(task2);
    myProject.add(task3);
    myProject.add(task4);
    myProject.add(task5);
    myProject.add(task6);
    myProject.add(task7);
    myProject.add(task8);
    myProject.add(task9);

    // myProject.printByLabel("label2");
    // myProject.finish("task5");
    // myProject.printByLabel("label2");

    cout << myProject;
    myProject.clear();
    cout << myProject;

    return 0;
}