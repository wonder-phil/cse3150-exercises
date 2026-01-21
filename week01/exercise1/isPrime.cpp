#include <iostream>
#include "isPrimeFunction.h"

using namespace std;



int main() {

    int testForPrime;

    cout << "Enter an integer" << endl;

    cin >> testForPrime;

    if (isPrimeInteger(testForPrime)) {
        cout << testForPrime << " is a prime number!" << endl;
    } else {
         cout << testForPrime << " is NOT a prime number!" << endl;
    }

}