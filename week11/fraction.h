#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
#include "./include/bigint.h"

using namespace std;

pair<bigint, bigint> product(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2);
pair<bigint, bigint> sum(pair<bigint, bigint> fraction1, pair<bigint, bigint> fraction2);



#endif