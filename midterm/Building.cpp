#include <iostream>
#include <string>

#include "Building.h"

using namespace std;

int count = 0;

Building::Building() {
    cout << " default constructor " << endl;
    if (0 == count) {
        count ++;
        foundation = new int[FOUNDATION_SIZE];
    }
}

Building::~Building() {
    if (0 != count) {
        count = 0;
        delete [] foundation;
    }
}
    
Building::Building(const Building & bldg) {
    if (1 >= count) {
        foundation = bldg.foundation;
    }
}

void Building::set_vals(int k) {
    for (int i=0; i < FOUNDATION_SIZE; i++) {
        foundation[i] = k;
    }
}

void Building::print_vals() {
     for (int i=0; i < FOUNDATION_SIZE; i++) {
        cout << foundation[i] << " ";
    }
    cout << endl;
}