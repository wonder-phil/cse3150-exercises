#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList ll, ll_1;

    cout << ll_1 << endl;

    ll.insertAtBeginning(-1);
    ll.insertAtBeginning(+1);
    ll.insertAtBeginning(-1);

    cout << ll << endl;

    ll.insertAtEnd(-44);

    cout << "-----ptr-to-end--------" << endl;

    Node * ptr_last = ll.getLastElement();

    cout << *ptr_last << endl;


    cout << "-------------" << endl;

    ll_1.insertAtBeginning(1);
    ll_1.insertAtBeginning(-1);
    ll_1.insertAtBeginning(1);

    cout << ll_1 << endl;
    ll_1.deleteNodeNumber(2);
    cout << ll_1 << endl;

    //LinkedList ll_2 = ll_1;
    ll_1.deleteNodeNumber(0);

    cout << "-------------" << endl;

    cout << ll_1 << endl;

    return 0;
}