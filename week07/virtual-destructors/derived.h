#include <iostream>
#include "base.h"

using namespace std;

class Derived : public Base {
    char * derivedPtr;

public:
    Derived() : derivedPtr{new char[2000]} {}
    ~Derived() { cout << "~Derived()" << endl; delete [] derivedPtr; }
};