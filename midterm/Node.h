#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;


/*
 *
 * A node's memory is laid out first, then the initalization list updates its details
 *
*/

struct Node {
        Node * next;
        int data;

        Node() : next{this} {};
        Node(int val) : data{val}, next{this} {}

    private: 
        friend ostream & operator<<(ostream & os, const Node & node);
};



#endif
