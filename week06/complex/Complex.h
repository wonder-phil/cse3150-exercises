#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
    
    double real, imag;

public:
    Complex();
    Complex(const Complex & complex);
    Complex(double real, double img);

    Complex & operator=(const Complex & complex);
    Complex & operator+=(const Complex & complex);
    
    double getReal() const;
    double getImag() const;

    void setReal(double _real);
    void setImag(double _imag);

   friend bool operator==(const Complex & left, const Complex & right);
   friend bool operator!=(const Complex & left, const Complex & right);
   friend ostream & operator<<(ostream & os, const Complex & complex);

};




#endif
