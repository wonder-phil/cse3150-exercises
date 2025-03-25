#include <iostream>
#include <vector>


#include "myFind.h"

bool myfind(std::vector<int> x, int v) {
    int small = 0, large = x.size() -1;

    while (small <= large) {
        int mid = (small + large)/2;
        if (v == x[mid]) return true;
        else if (v < x[mid]) large = mid -1;
        else small = mid + 1;
    }

    return false;
}


