#ifndef _BOTTOM_H
#define _BOTTOM_H

#include <iostream>

#include "Top.h"

using namespace std;

class Bottom : public Top {
    protected:
        int bInt;
    public:
       Bottom() { bInt = 99; }
       void printBint() { cout << bInt << endl; }
       int getTint() { return tInt; }
};

#endif