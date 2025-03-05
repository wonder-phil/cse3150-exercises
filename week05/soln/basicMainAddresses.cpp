#include <iostream>
#include <cmath>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList ll, ll_1;

    cout << "Empty: " << ll_1 << endl;

    ll.printAllNodeAddresses();

    ll.insertAtBeginning(1);
    cout << "one elt:" << ll << endl;
    ll.insertAtBeginning(2);
    ll.insertAtBeginning(5);
    cout << "three elts:" << ll << "end" << endl;
    ll.insertAtBeginning(3);

    ll.insertAtEnd(-44);

    cout << ll << endl;


    cout << "-----start-all-addresses--------" << endl;
    ll.copyAllNodesAddresses();
    ll.printAllNodeAddresses();
    cout << "-----end-all-addresses--------" << endl;

    ll.printTableNodesNextValue();

    cout << "pointer jumps" << endl;
    for (int i=0; i < log(ll.getSize()); i++)
        ll.runPointerJumps();
    cout << ll << endl;

    ll.printTableNodesNextValue();

    for (int i=0; i < 4; i++) {
        ll.runPointerJumps();
    }

    return 0;
}