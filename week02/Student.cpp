#include <iostream>

#include "Student.h"

Student get_student_struct_data() {

    Student student;

    string name;
    cout << "Enter name: " << endl;
    cin >> name;
    student.setName(name);

    cout << "Enter midterm: " << endl;
    cin >> student.midterm;

    cout << "Enter final: " << endl;
    cin >> student.final ;

    cout << "Enter a score or ^D for exit (no scores): " << endl;
    int score;
    while (cin >> score) {
        student.hw_grades.push_back(score);
        cout << "Enter another score or ^D for exit: " << endl;
    }

    return student;
}

ostream & operator<<(ostream & os, const Student & student) {
    os << student.getName()
        << " Midterm: "
        << student.midterm
        << " Final: "
        << student.final
        << " homework scores:";
        for (auto score : student.hw_grades) {
            os  << score
                << " ";
        }

    return os;
}