#ifndef _COMPLEX_H
#define _COMPLEX_H

class Complex {

    double real, imaginary;

    public:
        Complex() : real{0.0}, imaginary{0.0} {};
        Complex(const Complex & complex) : real{complex.real}, imaginary{complex.imaginary} {};
        Complex(double myReal, double myImaginary) : real{myReal}, imaginary{myImaginary} {};

        double getReal() const { return real; };
        double getImaginary() const { return imaginary; };

        Complex & operator+=(const Complex & complex);


};

#endif
