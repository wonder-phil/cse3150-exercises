#include <iostream>

#include "HoldsDynamicArray.h"


using namespace std;

ostream & operator<<(ostream & os, const HoldsDynamicArray & holdsDynamicArray) {
    if (holdsDynamicArray.arraySize == 0) {
        os << "Empty array \n" ;
    } else {
        for (int i =0; i < holdsDynamicArray.arraySize; i++) {
            os << holdsDynamicArray.myArray[i] << " ";
        }
        os << "\n" ;
    }
    return os;
}
