#include <iostream>

#include "top.h"
#include "bottom.h"

using namespace std;

int main() {

    Bottom bottom;
    bottom.publicInt = -9;
    //bottom.protectedInt = 5;

    cout << bottom.getProtectedInt() << endl;

    cout <<  bottom.publicInt << endl;
}