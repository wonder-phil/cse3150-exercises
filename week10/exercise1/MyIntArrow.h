#ifndef _MY_INT_ARROW_H_
#define _MY_INT_ARROW_H_

#include <iostream>


using namespace std;

struct MyIntArrow {
    int id;
    int one;
    int two;
    
    MyIntArrow(const MyIntArrow & iv) : id(iv.id), one(iv.one), two(iv.two) {
      
    };
    
    MyIntArrow() : id(-1), one(0), two(0) {};
    MyIntArrow(int _id, int _one, int _two) : id(_id), one(_one), two(_two) {};
};

#endif