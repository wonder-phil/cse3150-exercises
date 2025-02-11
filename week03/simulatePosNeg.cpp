#include <iostream>

#include "./prefixSumCode/prefixSum.h"
#include "fisherYates.h"
#include "simulatePosNeg.h"

void setupPlusAndMinuses(int ary[], int n){
    for (int i=0; i < n; i++) {
        ary[i] = 1;
    }

    for (int i=n; i < 2*n; i++) {
        ary[i] = -1;
    }
}


 int both_pos_and_neg(int initArray[], int iterations, int n) {

    int pos_and_neg = 0;

    for (int i = 0; i < iterations; i++) {
        setupPlusAndMinuses(initArray,n);
        
        fisher_yates(initArray, 2*n, std::rand);
        //cout << initArray[0] << " " << initArray[1] << endl;
        if (!non_negative_prefix_sum(initArray, 2*n) && !non_positive_prefix_sum(initArray, 2*n) ) {
            pos_and_neg ++;
        }
    }

    return pos_and_neg;
}