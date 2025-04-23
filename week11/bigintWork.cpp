#include <iostream>
#include "./include/bigint.h"
#include "fraction.cpp"

using namespace std;



ostream & operator<<(ostream & os, pair<bigint, bigint> & fraction) {
    os << fraction.first 
       << " / "
       << fraction.second;

    return os;
}


int main() {

    pair<bigint, bigint> fraction1("1","2"), fraction2("3","4");

    pair<bigint, bigint> newFractionProduct = product(fraction1, fraction2);
    
    cout << newFractionProduct << endl;

    pair<bigint, bigint> newFractionSum = sum(fraction1, fraction2);

    cout << newFractionSum << endl;

    bigint myBigInteger("1");
    const bigint two("2");
    int myInt = 1;

    for (int i = 0; i < 35; i++) {
        myInt *= 2;
        myBigInteger *= two;

        bigint compare(myInt);

        if (compare != myBigInteger) {
            cerr << "big int works, but int overflows: " << myBigInteger << " where i = " << i << endl;
            break;
        }
    }

    cout << myBigInteger << endl;
    cout << myInt << endl;

    return 0;
}