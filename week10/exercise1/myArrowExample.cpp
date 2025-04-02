#include <iostream>
#include <algorithm>
#include <vector>

#include "MyIntArrow.h"

using namespace std;


ostream & operator<<(ostream & os, const MyIntArrow & myIntA) {
    os << "id: " << myIntA.id << " "
       << "one: " << myIntA.one << " "
       << "two: " << myIntA.two;
    return os;
}

int main() {

    vector<MyIntArrow> myArrows = { {1, 4, -9}, {2,-55,4}, {3,-5050,33}, {4,329,5}, {5,-99,555},{6,44,-5,}, {7,22,6543},{8,3333,-666}, {9,-4,23}, {10,1,1} };

    sort(myArrows.begin(), myArrows.end(),
        [](const MyIntArrow & left, const MyIntArrow & right) -> bool {
            return (left.id > right.id);
        }
    );

    for ( auto myIntArrow : myArrows) {
        cout << myIntArrow << endl;
    }
    cout << endl;

    return 0;
}