#include <iostream>

#include "fisherYates.h"
#include "./prefixSumCode/prefixSum.h"
#include "simulatePosNeg.h"

using namespace std;

/*
 *
 */


int main() {
    int n, iterations;

    cout << "Enter the number of +1 values (there will be the same number of -1 values): " ;
    cin >> n;

    int initArray[2*n]; 

    cout << "How many iterations should we run this: ";
    cin >> iterations;

    setupPlusAndMinuses(initArray, n);
    int  pos_and_neg = both_pos_and_neg(initArray, iterations, n);

    cout << "Both positive and negative prefix sums: " << pos_and_neg << endl;
    cout << "Total +1 and -1 arrays: " << iterations << endl;
}