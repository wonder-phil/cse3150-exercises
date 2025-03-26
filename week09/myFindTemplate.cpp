#include <iostream>
#include <vector>


//#include "myFindTemplate.h"

template<typename T> // , bool (*cmp)(const T & a, const T & b)
bool myfind(std::vector<T> x, T & v) {
    int small{0}, large = x.size() -1;

    while (small <= large) {
        int mid = (small + large)/2;
        if (v == x[mid]) return true;
        else if (v < x[mid]) large = mid -1;
        else small = mid + 1;
    }

    return false;
}


