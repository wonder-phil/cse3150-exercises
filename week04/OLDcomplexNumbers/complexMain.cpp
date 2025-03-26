#include <iostream>

#include "complex.h"

using namespace std;


ostream & operator<<(std::ostream & os, const Complex & complex) {
  os << complex.getReal() 
     << " "
     << complex.getImaginary() 
     << " "; 

     return os;
};

int main() {

    Complex complex;

    cout << complex << endl;
    

};