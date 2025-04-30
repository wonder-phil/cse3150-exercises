#include <iostream>

#include "fraction.cpp"

using namespace std;

int main() {

    pair<bigint, bigint> fraction1(1,2), fraction2(3,4);

    pair<bigint, bigint> myProduct = product(fraction1, fraction2);

    cout << myProduct << endl;

    bigint myBigInt(1);
    int myInt = 1;

    bigint two(2);

    for (int i=0; i < 50; i++) {
        myBigInt *= 2;
        myInt *= 2;

        bigint compare(myInt);

        if(compare != myBigInt) {
            cerr << myInt << " and " << myBigInt << endl;
            cerr << "bigInt is not the same as int for i: " << i << endl;
            break;
        }

    }

    long myLong = 1;
    myBigInt = 1;

    for (int i=0; i < 100; i++) {
        myBigInt *= 2;
        myLong *= 2;

        bigint compare(myLong);

        if(compare != myBigInt) {
            cerr << myLong << " and " << myBigInt << endl;
            cerr << "bigInt is not the same as long for i: " << i << endl;
            break;
        }

    }

    return 0;
}