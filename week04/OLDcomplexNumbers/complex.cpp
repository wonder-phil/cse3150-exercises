#include <iostream>

#include "complex.h"

using namespace std;





Complex & Complex::operator+=(const Complex & complex) {
    real += complex.real;
    imaginary += complex.imaginary;

    return *this;
}

