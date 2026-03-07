#ifndef _BASE_H
#define _BASE_H

#include <iostream>

using namespace std;

class Base {
    int * basePtr;

public:
    Base(): basePtr{new int[1000]} {}

    //virtual 
    ~Base() { cout << "~Base()" << endl; delete [] basePtr; }
};


#endif
