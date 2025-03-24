#include <iostream>

#include "MyStack.h"

struct myVal {
    int v;
    MyVal(int i) : v(i) {}
    
}

int main() {

    using namespace std;
    
    MyStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);

    cout << mstack.top() << endl;


    return 0;
}