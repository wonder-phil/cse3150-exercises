#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct Student {

    Student() { 
        hw_grades = nullptr;
    }
    Student(string _name, int _final, int _number_of_homeworks) {
        name = _name;
        final = _final;
        number_of_homeworks = _number_of_homeworks;
        hw_grades = new int[number_of_homeworks];
    }
    ~Student() {
        if (nullptr != hw_grades) {
            delete [] hw_grades;
        }
    }

    string name;
    int final;
    int * hw_grades;
    int number_of_homeworks;


    string getName() const { return name; }
    void setName(string _name) { name = _name; }
};

ostream & operator<<(ostream & os, const Student & student);

Student get_student_struct_data();

#endif