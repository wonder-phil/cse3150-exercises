#ifndef _NODE_
#define _NODE_

struct Node {
    int data;
    struct Node * next;

    Node() {
        next = nullptr;
        data = -1;
    }
};

static Node * root;

Node * build_linked_list(int nodes) ;
void print_linked_list(Node * linked_list);

#endif
