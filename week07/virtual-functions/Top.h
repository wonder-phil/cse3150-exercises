#ifndef _TOP_H
#define _TOP_H

#include <iostream>

using namespace std;

class Top {
    
public:
    Top() { cout << "Top Constructor" << endl; }
    virtual void function() { cout << "Top function Top::function" << endl; } 
    virtual  ~Top() { cout << "Top Destructor" << endl; }
};


#endif