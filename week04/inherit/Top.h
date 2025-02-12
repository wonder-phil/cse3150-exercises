#ifndef _TOP_H
#define _TOP_H

#include <iostream>

using namespace std;

class Top {
    public:
        Top() {
            cout << "Top constructor" << endl;
        }

        ~Top() {
            cout << "Top destructor" << endl;
        }
};

#endif