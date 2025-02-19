#include <iostream>

#include "node.h"

using namespace std;

int main() {

    struct Node * linked_list_one_elt = build_linked_list(1);
    print_linked_list(linked_list_one_elt->next);

    struct Node * linked_list_several_elts = build_linked_list(3);
    print_linked_list(linked_list_several_elts->next);

    return 0;
}