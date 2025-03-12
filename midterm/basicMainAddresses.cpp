#include <iostream>

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

    ll.recursivePointerJump(ll.getFirstElement());

    for (int i=0; i < ll.getSize(); i++) {
        cout << ll.getAddressFromArray(i) << " " ;
        cout << ll.getAddressFromArray(i)->next << " " ;
        cout << ll.getAddressFromArray(i)->data << " " << endl;
    }

    return 0;
}