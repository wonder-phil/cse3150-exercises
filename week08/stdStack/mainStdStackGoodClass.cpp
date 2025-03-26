#include <iostream>

#include <stack>
#include <queue>

#include "GoodClass.h"

using namespace std;


int main() {

    stack<GoodClass> s ;

    GoodClass gc1("Grace", 99);
    GoodClass gc2("Alonzo", 98);
    GoodClass gc3("Charles", 101);

    s.push(gc1);
    s.push(gc2);
    s.push(gc3);

    while (! s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}