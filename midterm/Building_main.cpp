#include <iostream>
#include <string>

#include "Building.h"

using namespace std;

int main() {

    Building building_1;
    building_1.set_vals(99);

    building_1.print_vals(); // output: 99 99 99 99 99 99 99 99 99 99
    Building building_2 = building_1;
    Building building_3 = building_1;

    building_2.print_vals(); // output: output 99 99 99 99 99 99 99 99 99 99
    building_3.print_vals(); // output: output 99 99 99 99 99 99 99 99 99 99


    return 0;
}