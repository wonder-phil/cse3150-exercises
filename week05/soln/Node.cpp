#include <iostream>

#include "Node.h"

using namespace std;


ostream & operator<<(ostream & os, const Node & node) {
    os  << node.data 
        << " at ("
        << & node
        << ") and next:"
        << static_cast<void *>( node.next ) ;

    return os;
};