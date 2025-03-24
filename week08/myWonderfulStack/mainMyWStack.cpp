#include <iostream>

#include "MyWStack.h"
#include "GoodClass.h"

using namespace std;

int main() {

    MyWStack<GoodClass, 10> swStack;

    GoodClass gc1("Richard", 99);
    GoodClass gc2("Nick", 100);
    GoodClass gc3("Steve", 105);


    swStack.push(gc1);
    swStack.push(gc2);
    swStack.push(gc3);

    while (! swStack.empty() ) {
        cout << swStack.top() << endl;
        try {
            swStack.pop();
        } catch(exception e) {
            cerr << e.what() << endl;
        }
    }

    try {
        swStack.pop();
    } catch(StackEmptyException & e) {
        cerr << "Error outside loop: " << e.what() << endl;
    }

}