#ifndef _BOTTOM_H
#define _BOTTOM_H

#include <iostream>
#include "Middle.h"

using namespace std;

class Bottom : public Middle {
    
public:
    Bottom() { cout << "Bottom Constructor" << endl; }
    void function() override { cout << "Bottom function Bottom::function" << endl; } 
    ~Bottom() { cout << "Bottom Destructor" << endl; }
};


#endif