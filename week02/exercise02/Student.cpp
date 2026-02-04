#include <iostream>

#include "Student.h"

Student get_student_struct_data() {

    string name;
    int final;
    int total_homeworks;

    cout << "Enter name: " << endl;
    cin >> name;

    cout << "Enter final: " << endl;
    cin >> final ;

    cout << "How many homeworks: " << endl;
    cin >> total_homeworks;

    Student student(name,final,total_homeworks);


    cout << "Enter a score: " << endl;
    int score;
    for (int i = 0; i < student.number_of_homeworks; i++) {
        cin >> score;
        student.hw_grades[i] = score;
        cout << "Enter another score: " << endl;
    }

    return student;
}

ostream & operator<<(ostream & os, const Student & student) {
    os << student.getName()
        << " Final: "
        << student.final
        << " homework scores:";
        for (int i = 0; i < student.number_of_homeworks; i++) {
            os  << student.hw_grades[i]
                << " ";
        }

    return os;
}