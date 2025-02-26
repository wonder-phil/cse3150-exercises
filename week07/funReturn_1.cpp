#include <iostream>

using namespace std;

class BigClass {
        int * array;
        int arraySize;
    public:
        BigClass(int size) : arraySize{size}, array{new int[size]} {
            cout << "Constructor" << endl;
        }
        BigClass(const BigClass & bc) : array{new int[bc.arraySize]}, arraySize(bc.arraySize) {
            cout << "Copy constructor" << endl;
            for(int i=0; i < arraySize; i++) {
                array[i] = bc.array[i];
            }
        }

        BigClass(BigClass && bc) {
            cout << "Move constructor" << endl;
        }

        ~BigClass() {
            cout << "Destructor" << endl;
            delete [] array;
        }

        int getSize() { return arraySize; }
};

BigClass myFunction() {
    cout << "   First line in myFunction" << endl;
    BigClass bc(100);
    cout << "   After BigClass in myFunction" << endl;

    return bc;
}

int main() {
    cout << "First line" << endl;
    BigClass bc = myFunction();
    cout << "After function invocation" << endl;

    cout << bc.getSize() << endl;
    
    return 0;
}