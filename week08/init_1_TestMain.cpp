#include <iostream>

using namespace std;

class Test {
    int a;
    int b;
    int c;

    public:
        Test() : c{b+1}, b{a+1}, a{5} {
            cout << "a: " << a << " b: " << b << " c: " << c << endl;
        }
};

int main() {

    Test test;

    return 0;
}