#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {

    Student(string _name, int _number, int _total_homeworks) {
        name = _name;
        number = _number;
        total_homeworks = _total_homeworks;
        homeworks = new int[total_homeworks];
    }

    ~Student() {
        delete [] homeworks;
    }

    string name;
    int number;

    int midtermExam;
    int finalExam;

    int total_homeworks;
    int * homeworks;

};


ostream & operator<<(std::ostream & os, const Student & student) {
  os << student.name 
     << " "
     << student.number;

     for (int i=0; i < student.total_homeworks; i++){
        os << student.homeworks[i]
           << " ";
     }

     return os;
};


#endif
