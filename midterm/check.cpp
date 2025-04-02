#include <iostream>

using namespace std;

struct Test {
    int one, two;

    Test(int one, int two) : one(one), two(two) {}
};

int main() {
    Test testMe(2,3);

    cout << testMe.one << endl;
    cout << testMe.two << endl;

    return 0;
}