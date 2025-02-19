#include <iostream>

#include "node.h"

using namespace std;

Node * build_linked_list(int total_nodes) {
    if (0 == total_nodes) {
        return nullptr;
    } else {
        Node * linked_list = new Node;
        root = linked_list;
        
        for (int i = 0; i < total_nodes; i++) {
            linked_list->next = new Node;
            linked_list = linked_list->next;
            linked_list->data = i+1;
        }
    }
    return root;
}


void print_linked_list(Node * linked_list) {
    Node * traverse = linked_list;

    while (nullptr != traverse) {
        cout << traverse->data << endl;
        traverse = traverse->next;
    }
}