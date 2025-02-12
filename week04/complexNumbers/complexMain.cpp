#include <iostream>

#include "complexNumber.h"

using namespace std;

ostream & operator<<(ostream & os, const Complex & complex) {
    os << complex.getReal()
       << " + "
       << complex.getImaginary()
       << "i ";

    return os;
};

int main() {

    Complex c1(2.0,3.5);
    Complex d2(-5.0, 11.2);

    Complex x;

    cout << c1 << endl;
    cout << d2 << endl;

    d2 += c1;

    cout << d2 << endl;

    cout << "-------------" << endl;

    x = c1 + c1;

    cout << x << endl;

    return 0;
}