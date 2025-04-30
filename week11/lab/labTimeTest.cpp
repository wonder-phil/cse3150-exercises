#include <iostream>
#include <chrono>
#include <limits>

#include "../include/bigint.h"

using namespace std;

int main() {

    int limit;
    cout << "Enter the number of iterations: " ;
    cin >> limit;
    cout << endl;

    int maxInt = numeric_limits<int>::max();
    long maxLong = numeric_limits<long>::max();
    bigint maxLongBigInt = bigint(maxLong);

    cout << "int*int" << endl;
    auto start = chrono::high_resolution_clock::now();

    int a = 1, b=2;
    for (int i=0; i < limit; i++) {
        a = a*b;
        if (a >= maxInt) {
            a = 1;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    cout << "-------" << endl;

    
    cout << "long*long" << endl;
    start = chrono::high_resolution_clock::now();
    {
        long a = 1, b=2;
        for (int i=0; i < limit; i++) {
            a = a*b;
            if (a >= maxLong) {
                a = 1;
            }
        }
    }
    cout << "a = " << a << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    cout << "-------" << endl;
    cout << "bigint*bigint" << endl;

    start = chrono::high_resolution_clock::now();

    bigint biga = 1, bigb = 2;
    for (int i=0; i < limit; i++) {
        biga = biga* bigb;
        if (biga >= maxLongBigInt) {
            biga = 1;
        }
    }

    end = chrono::high_resolution_clock::now();
    duration =chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}