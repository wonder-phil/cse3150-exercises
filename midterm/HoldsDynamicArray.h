#ifndef _HOLDS_DYAMIC_H
#define _HOLDS_DYAMIC_H

#include <iostream>

using namespace std;

class HoldsDynamicArray {

    friend ostream & operator<<(ostream & os, const HoldsDynamicArray & holdsDynamicArray);

    private:
        int * myArray;
        int arraySize;

    public:

        HoldsDynamicArray(): myArray{nullptr}, arraySize{0} {}
        HoldsDynamicArray(int size): myArray{new int[size]}, arraySize{size} {
            for (int i=0 ; i < arraySize; i++ ) {
                myArray[i] = 2*i;
            }
        }
        HoldsDynamicArray(const HoldsDynamicArray & hda) : myArray{new int[hda.arraySize]}, arraySize{hda.arraySize} {
            for (int i=0 ; i < arraySize; i++ ) {
                myArray[i] = hda.myArray[i];
            }
        }

        HoldsDynamicArray(HoldsDynamicArray && hda) : myArray{hda.myArray}, arraySize{hda.arraySize} {
            hda.myArray = nullptr;
            hda.arraySize = 0;
        }

        HoldsDynamicArray & operator=(HoldsDynamicArray & hda) {
            if (& hda != this) {
                if (myArray) {
                    delete [] myArray;
                }
                myArray = hda.myArray;
                arraySize = hda.arraySize;
            }

            return *this;
        }

        ~HoldsDynamicArray() {
            if (nullptr) {
                delete [] myArray;
            }
        }
};

#endif