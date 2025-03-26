#ifndef _MY_FIND_H_
#define _MY_FIND_H

#include <iostream>
#include <vector>


template<typename T, bool (*cmp)(const T & a, const T & b)>
bool myfind(std::vector<T> x, T & v, bool (*cmp)(const T & a, const T & b));


#endif