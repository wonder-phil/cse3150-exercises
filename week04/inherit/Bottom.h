#ifndef _BOTTOM_H
#define _BOTTOM_H

#include <iostream>

#include "Top.h"


using namespace std;


class Bottom : Top {
    public:
        Bottom() {
            cout << "Bottom constructor" << endl;
        }
        ~Bottom() {
            cout << "Bottom destructor" << endl;
        }
};

#endif