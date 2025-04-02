#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> myVector = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

    int myEvenSum = 0;

    for_each(myVector.begin(), myVector.end(),
            [&myEvenSum](int elt) { 
                if( 0 == elt % 2) {
                    myEvenSum += elt;
                    cout << elt << endl;
                }
            }
    );

    cout << "Sum of evens: " << myEvenSum << endl;

    return 0;
}