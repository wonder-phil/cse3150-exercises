#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList ll, ll_1;

    cout << "Empty: " << ll_1 << endl;

    ll.insertAtBeginning(1);
    cout << "one elt:" << ll << endl;
    ll.insertAtBeginning(2);
    ll.insertAtBeginning(5);
    cout << "three elts:" << ll << "end" << endl;
    ll.insertAtBeginning(3);

    cout << ll << endl;

    ll.insertAtEnd(-44);

    cout << "-----ptr-to-end--------" << endl;

    Node * ptr_last = ll.getLastElement();

    cout << *ptr_last << endl;

    cout << "---List again------" << endl;
    cout << ll << endl;


    cout << "-------------" << endl;

    ll_1.insertAtBeginning(1);
    ll_1.insertAtBeginning(2);
    ll_1.insertAtBeginning(3);

    cout << ll_1 << endl;
    ll_1.deleteNodeNumber(2);
    cout << ll_1 << endl;

   
    ll_1.deleteNodeNumber(0);
    cout << "after delete(0): " << ll_1 << " end" << endl;

    ll_1.insertAtBeginning(99);

    cout << "-------------" << endl;

    cout << ll_1 << endl;

    LinkedList ll_2 = ll_1;

    cout << "-----Same--------" << endl;
    cout << ll_1 << endl;
    cout << ll_2 << endl;
    cout << "-----Same--------" << endl;

    return 0;
}