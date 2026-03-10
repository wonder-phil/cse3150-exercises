#ifndef _MIDDLE_H
#define _MIDDLE_H

#include <iostream>
#include "Top.h"

using namespace std;

class Middle : public Top {
    
public:
    Middle() { cout << "Middle Constructor" << endl; }
    void function() override { cout << "Middle function Middle::function" << endl; } 
    ~Middle() { cout << "Middle Destructor" << endl; }
};


#endif