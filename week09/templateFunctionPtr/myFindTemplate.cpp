#include <iostream>
#include <vector>


//#include "myFindTemplate.h"

template<typename T>
bool lessThan(const T & a, const T & b) {
    if (a - b < 0.005 || b - a < 0.005) {
        return true;
    }
    return false;
}

template<typename T>
bool myfind(std::vector<T> x, T & v, bool (*cmp)(const T & a, const T & b)) {
    int small{0}, large = x.size() -1;

    while (small <= large) {
        int mid = (small + large)/2;
        if (v == x[mid]) return true;
        else if (!cmp(v, x[mid])) large = mid -1;
        else small = mid + 1;
    }

    return false;
}


