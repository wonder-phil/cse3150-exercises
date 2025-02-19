#include <iostream>

#include "Bottom.h"

using namespace std;

int main() {

    Bottom bottom;
    bottom.myFunction();

    bottom.Top::myFunction();

    return 0;
}
