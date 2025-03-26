#include <iostream>

#include "LinkedList.h"

using namespace std;

int main() {

    LinkedList ll;
    ll.insertAtBeginning(-1);
    ll.insertAtBeginning(+1);
    ll.insertAtBeginning(-1);

    cout << ll << endl;

    return 0;
}