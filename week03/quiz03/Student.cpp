#include <iostream>
#include <string>

#include "Student.h"


using namespace std;

Student::Student(const Student & student) {
    name = student.name;
    number_of_homeworks = student.number_of_homeworks;
    home_work_scores = new int[number_of_homeworks];
    for (int i=0; i < number_of_homeworks; i++) {
        home_work_scores[i] = student.home_work_scores[i];
    }
}

Student::Student(string _name, int _number_of_homeworks) {
    name = _name;
    number_of_homeworks = _number_of_homeworks;
    home_work_scores = new int[number_of_homeworks];
       for (int i=0; i < number_of_homeworks; i++) {
        home_work_scores[i] = student.home_work_scores[i];
    }
}

Student::~Student() {
    if (nullptr != home_work_scores) {
        delete [] home_work_scores;
    }
}