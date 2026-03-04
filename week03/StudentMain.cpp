#include <iostream>

#include "Student.h"

using namespace std;

int main() {

    Student *root = nullptr, * allStudents = nullptr;

    int numberOfStudents, numberOfHws;
    cout << "Enter the number of students: " << endl;
    cin >>  numberOfStudents;

    cout << "Enter the number of homeworks: " << endl;
    cin >> numberOfHws;

    for (int i = 0; i < numberOfStudents; i++) {
        Student * student = get_student_struct_data(numberOfHws);
        if (0 == i) root = student;
        allStudents->nextStudent = student;
    }

    Student * aStudent = root;
    while (aStudent) {
        cout << endl << * aStudent << endl;
        aStudent = aStudent->nextStudent;
    }
    

    return 0;
}