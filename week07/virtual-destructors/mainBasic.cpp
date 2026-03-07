#include <iostream>

#include "derived.h"


using namespace std;

int main() {

    Base *b = new Derived();
    delete b;

    cout << "START---no-ptr-no-refs-------" << endl;
    {
        Derived d;
    }
    cout << "END---no-ptr-no-refs-------" << endl;
    
   

    return 0;
}