#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct Student {

    Student();
    Student(string _name, int _final, int _number_of_homeworks);
    Student(const Student & student);
    ~Student();

    string name;
    int final;
    int * hw_grades;
    int number_of_homeworks;

    string getName() const ;
    void setName(string _name) ;
};

ostream & operator<<(ostream & os, const Student & student);

Student get_student_struct_data(int numberOfHws);

#endif