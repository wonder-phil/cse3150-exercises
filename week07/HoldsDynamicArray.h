#ifndef _HOLDS_DYNAMIC_ARRAY_H
#define _HOLDS_DYNAMIC_ARRAY_H

#include <iostream>

using namespace std;

class HoldsDynamicArray {

    private:
        int arraySize;
        int * myArray;

    public:
        HoldsDynamicArray() : arraySize{0}, myArray{nullptr} {}
        HoldsDynamicArray(int newSize) : arraySize{newSize}, myArray{new int[newSize]} {
            for (int i=0; i < arraySize; i++) {
                myArray[i] = i*2;
            }
        }
        HoldsDynamicArray(const HoldsDynamicArray & holdsDynamicArray) : 
                arraySize{holdsDynamicArray.arraySize}, 
                myArray{new int[arraySize]} { }

        HoldsDynamicArray(HoldsDynamicArray && holdsDynamicArray) :
            myArray{holdsDynamicArray.myArray}, 
            arraySize{holdsDynamicArray.arraySize} {

                holdsDynamicArray.myArray = nullptr;
                holdsDynamicArray.arraySize = 0;
            }
            

        HoldsDynamicArray & operator=(HoldsDynamicArray && holdsDynamicArray) {
            if (& holdsDynamicArray != this) {
                if (myArray) {
                    delete [] myArray;
                }
                myArray = holdsDynamicArray.myArray;
                arraySize = holdsDynamicArray.arraySize;

                holdsDynamicArray.myArray = nullptr;
                holdsDynamicArray.arraySize = 0;
            }
            return *this;
        }


        ~HoldsDynamicArray() { 
            if (myArray) {
                delete [] myArray;
             }
        }

        friend ostream & operator<<(ostream & os, const HoldsDynamicArray & holdsDynamicArray);
};


#endif
