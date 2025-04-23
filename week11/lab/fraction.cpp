#include <iostream>


#include "../include/bigint.h"

//#include "fraction.h"

using namespace std;

template<typename T>
ostream & operator<<(ostream & os, pair<T, T> & fraction) {
    os << fraction.first 
       << " / "
       << fraction.second;

    return os;
}



pair<int, int> product(pair<int, int> fraction1, pair<int, int> fraction2) {
    return pair<int, int>(fraction1.first * fraction2.first, fraction1.second * fraction2.second);
}

pair<long, long> product(pair<long, long> fraction1, pair<long, long> fraction2) {
    return pair<long, long>(fraction1.first * fraction2.first, fraction1.second * fraction2.second);
}

pair<bigint, bigint> product(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2) {
    return pair<bigint, bigint>(fraction1.first * fraction2.first, fraction1.second * fraction2.second);
}

