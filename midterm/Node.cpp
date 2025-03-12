#include <iostream>

#include "Node.h"

using namespace std;


ostream & operator<<(ostream & os, const Node & node) {
    os  << node.data 
        << " at ("
        << & node
        << ")";

    return os;
};