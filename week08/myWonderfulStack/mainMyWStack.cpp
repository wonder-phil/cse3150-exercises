#include <iostream>

#include "MyWStack.h"

using namespace std;

int main() {

    MyWStack<int, 10> swStack;

    swStack.push(-5);
    swStack.push(99);
    swStack.push(-101);

    while (! swStack.empty() ) {
        cout << swStack.top() << endl;
        swStack.pop();
    }

}