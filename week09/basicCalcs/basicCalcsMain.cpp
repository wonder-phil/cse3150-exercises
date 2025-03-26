#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

 
struct Distance {
    int vector1, vector2;
    double alpha;
    Distance(int v1, int v2, double _a) : vector1{v1}, vector2{v2}, alpha{_a} {}
};

int main() {
    vector<int> myVector = {9,8,7,6,5,4,3,2,1};

    for (auto v :  myVector) {
        cout << v << " ";
    }
    cout << endl;

    sort(myVector.begin(), myVector.end());

    for (auto v :  myVector) {
        cout << v << " ";
    }
    cout << endl;

    cout << "--------------"  << endl;

    vector<Distance> myDist = { {1,4,5.5}, {1,3,1.5}, {1,2,0.5}, };


    for (auto d: myDist) {
        cout << d.alpha << " ";
    }
    cout << endl;

    sort(myDist.begin(), myDist.end(), [](Distance a, Distance b)
    {
        return a.alpha < b.alpha;
    });

    for (auto d: myDist) {
        cout << d.alpha << " ";
    }
    cout << endl;

    return 0;
}
