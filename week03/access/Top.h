#ifndef _TOP_H
#define _TOP_H

#include <iostream>

using namespace std;

class Top {
    protected: 
        int tInt;
    public:
       Top() { tInt = -4; }
       void printTint() { cout << tInt << endl; }
};

#endif