#include <iostream>

#include "complexNumber.h"

using namespace std;

Complex & Complex::operator+=(const Complex & complex) {
    real += complex.real;
    imaginary += complex.imaginary;

    return *this;
}

Complex & Complex::operator+(const Complex & complex) {
    real += complex.real;
    imaginary += complex.imaginary;

    return *this;
}