#include <iostream>
#include <vector>

#include "Student.h"

using namespace std;

int main() {

    vector<Student> allStudents;

    int numberOfStudents, numberOfHws;
    cout << "Enter the number of students: " << endl;
    cin >>  numberOfStudents;

    cout << "Enter the number of homeworks: " << endl;
    cin >> numberOfHws;

    for (int i = 0; i < numberOfStudents; i++) {
        Student student = get_student_struct_data(numberOfHws);
        allStudents.push_back(student);
    }

    for (auto aStudent : allStudents) {
        cout << endl << aStudent << endl;
    }
    

    return 0;
}