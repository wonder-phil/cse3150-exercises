#include <iostream>
#include <vector>
#include <algorithm>

#include "MyIntArrow.h"

using namespace std;

ostream & operator<<(ostream & os, const MyIntArrow & myIntArrow) {
    os << "id: " << myIntArrow.id << " "
       << "one: " << myIntArrow.one  << " "
       << "two: " << myIntArrow.two  << " ";
    return os;
}

int main() {
    vector<MyIntArrow> vectorOfArrows = { {1, 3, 4 }, { 2, 9, -5 }, { 3, 99, 21 }, { 4, 101, -55 }, { 5, -4092, 942 } };

    sort(   vectorOfArrows.begin(),
            vectorOfArrows.end(),
            [](MyIntArrow & left, MyIntArrow & right) -> bool {
                return left.id > right.id;
            }
        );

        for ( auto miArrow : vectorOfArrows) {
            cout << miArrow << endl;
        }


    return 0;
}