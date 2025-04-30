#include <iostream>
#include <chrono>
#include <limits>

#include "../include/bigint.h"
#include "./fraction.cpp"

using namespace std;

int main() {

    int limit;
    cout << "Enter the number of iterations: " ;
    cin >> limit;
    cout << endl;

    int maxInt = numeric_limits<int>::max();
    long maxLong = numeric_limits<long>::max();
    bigint maxLongBigInt = bigint(maxLong);

    cout << "pair<int,int> * pair<int,int>" << endl;
    auto start = chrono::high_resolution_clock::now();

    pair<int,int> a = {1,1}, b = {1,2};
    for (int i=0; i < limit; i++) {
        a = product(a,b);
        if (a.second >= maxInt) {
            a = {1,1};
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    cout << "-------" << endl;

    
    cout << "pair<long,long> * pair<long,v>" << endl;
    start = chrono::high_resolution_clock::now();
    {
        pair<long,long> a = {1,1}, b = {1,2};
        for (int i=0; i < limit; i++) {
            a = product(a,b);
            if (a.second >= maxLong) {
                a = {1,1};
            }
        }
    }
    cout << "a = " << a << endl;
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    cout << "-------" << endl;
    cout << "pair<bigint,bigint> * pair<bigint,bigint>" << endl;

    start = chrono::high_resolution_clock::now();

    pair<bigint,bigint> biga = {1,1}, bigb = {1,2};
    for (int i=0; i < limit; i++) {
        biga = product(biga, bigb);
        if (biga.second >= maxLongBigInt) {
            biga = {1,1};
        }
    }

    end = chrono::high_resolution_clock::now();
    duration =chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}