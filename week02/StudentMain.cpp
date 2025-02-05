#include <iostream>

#include "Student.h"

using namespace std;

int main() {

    string name = "Albert";

    Student firstStudent(name, 199, 10);
    Student secondStudent = firstStudent;

    secondStudent.name = "Ada";
    secondStudent.number = -432;

    cout << firstStudent << endl;
    cout << secondStudent << endl;


    return 0;
}