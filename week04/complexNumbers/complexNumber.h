#ifndef _COMPLEX_NUMBER_H
#define _COMPLEX_NUMBER_H

class Complex {
    
    double real, imaginary;

    public:
        Complex() : real{0.0}, imaginary{0.0} {}
        Complex(double r, double i) : real{r}, imaginary{i} {}

        double getReal() const { return real; }
        double getImaginary() const { return imaginary; }

        Complex & operator+=(const Complex & complex);

        Complex & operator+(const Complex & complex);

};

#endif
