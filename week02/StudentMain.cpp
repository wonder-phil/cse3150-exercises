#include <iostream>

#include "Student.h"

using namespace std;

int main() {

    string name = "Albert";

    Student firstStudent(name, 199, 10);
    Student secondStudent = firstStudent;

    secondStudent.name = "Ada";
    secondStudent.number = -432;

    firstStudent.homeworks[3] = -99;
    secondStudent.homeworks[4] = 7777;

    cout << firstStudent << endl;
    cout << secondStudent << endl;

    cout << firstStudent.homeworks << endl;
    cout << secondStudent.homeworks << endl;

    return 0;
}