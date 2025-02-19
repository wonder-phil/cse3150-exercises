#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;



struct Node {
    Node * next;
    int data;

    Node(int val) : data{val}, next{nullptr} {}
};


ostream & operator<<(ostream & os, const Node & node) {
    os  << node.data 
        << " at ("
        << & node
        << ")";

    return os;
};

#endif
