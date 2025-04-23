#include <iostream>

#include "fraction.h"

#include "./include/bigint.h"

using namespace std;



pair<bigint, bigint> product(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2) {
    bigint numerator = fraction1.first * fraction2.first;
    bigint denominator = fraction1.second * fraction2.second;

    return pair<bigint, bigint>(numerator, denominator);
}

pair<bigint, bigint> sum(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2) {
    bigint numerator = fraction1.first * fraction2.second + fraction1.second * fraction2.first;
    bigint denominator = fraction1.second * fraction2.second;

    bigint myGcd = big_gcd(numerator, denominator);

    return pair<bigint, bigint>(numerator / myGcd, denominator / myGcd);
}
