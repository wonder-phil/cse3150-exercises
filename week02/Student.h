#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct Student {
 
    public: 
        int final;
        int midterm;
        vector<int> hw_grades;

    private: 
        string name;

    public:
        string getName() const { return name; }
        void setName(string _name) { name = _name; }
};

ostream & operator<<(ostream & os, const Student & student);

Student get_student_struct_data();

#endif