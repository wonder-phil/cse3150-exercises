#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

using namespace std;

static bool memoryFreed = false;

struct Student {

    Student(string _name, int _number, int _total_homeworks) {
        name = _name;
        number = _number;
        total_homeworks = _total_homeworks;
        homeworks = new int[total_homeworks];
    }

   Student(const Student & student) : name(student.name), number(student.number), total_homeworks(student.total_homeworks) {
        if (nullptr != student.homeworks) {
            homeworks = new int[total_homeworks];
            for (int i=0; i < total_homeworks; i++) {
                homeworks[i] = student.homeworks[i];
            }
        }
    }

    ~Student() {
        delete [] homeworks;
    }

    string name;
    int number;

    int midtermExam;
    int finalExam;

    int total_homeworks;
    int * homeworks = nullptr;

};


ostream & operator<<(std::ostream & os, const Student & student) {
  os << student.name 
     << " "
     << student.number
     << " ";

     for (int i=0; i < student.total_homeworks; i++){
        os << student.homeworks[i]
           << " ";
     }

     return os;
};


#endif
