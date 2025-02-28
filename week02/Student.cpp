
#include "Student.h"

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
