#include <iostream>

#include "Bottom.h"

using namespace std;

int main() {

    Bottom * bottom = new Bottom();

    bottom->printBint();
    bottom->printTint();

    cout << "Accessing a protected value: " << bottom->getTint() << endl;

    return 0;
}
