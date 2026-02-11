#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int *home_work_scores;
    int number_of_homeworks;

    Student() : home_work_scores{nullptr} {}
    Student(const Student & student);
    Student(string name, int _number_of_homeworks);
    ~Student();
};

#endif


