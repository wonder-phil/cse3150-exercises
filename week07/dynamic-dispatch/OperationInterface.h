#ifndef _OPERATIONINTERFACE_H
#define _OPERATIONINTERFACE_H

#include <iostream>
#include <vector>

using namespace std;

class OperationInterface {
public:
    virtual double compute(double a, double b) { return 0.0; } ; // pure virtual
    virtual const char* name() { return "OP"; };
     virtual ~OperationInterface() {};
};

#endif