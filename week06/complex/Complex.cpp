#include "Complex.h"

Complex::Complex() : real{0.0}, imag{0.0} {}
Complex::Complex(double _real, double _imag) : real{_real}, imag{_imag} { }

Complex::Complex(const Complex & complex) {
    real = complex.real;
    imag = complex.imag;
}

Complex & 
Complex::operator=(const Complex & complex) {
    if (& complex == this) {
        return *this;
    } else {
        real = complex.real;
        imag = complex.imag;
        return *this;
    }
}
 
Complex & 
Complex::operator+=(const Complex & complex){
    real += complex.real;
    imag += complex.imag;

    return *this;
}


double Complex::getReal() const { return real; }
double Complex::getImag() const { return imag; }

void Complex::setReal(double _real) { real = _real; }
void Complex::setImag(double _imag) { imag = _imag; }



bool 
operator==(const Complex & left, const Complex & right) {
   return (left.real == right.real && left.imag == right.imag);
}

bool 
operator!=(const Complex & left, const Complex & right) {
   return !(left == right);
}


ostream & operator<<(ostream & os, const Complex & complex) {
    os << "real: "
       << complex.real
       << " imag: "
       << complex.imag;

    return os;
}

