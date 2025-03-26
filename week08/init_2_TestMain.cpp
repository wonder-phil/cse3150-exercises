#include <iostream>

using namespace std;


struct Item {
    int x;

    Item() {
        cout << "Item default constructor" << endl;
        x = -1;
    }

    Item(int _x) {
        x = _x;
        cout << "Item param. constructor: starting x: " << x << endl;
    }

    Item(const Item & item) {
        cout << "Copy constructor" << endl;
        x = item.x;
    }

    Item operator+(const Item & item) {
        cout << "operator+ " << x << " " << item.x << endl;

        return Item(x+item.x); //
    }
};

ostream & operator<<(ostream & os, const Item & item) {
    os << item.x;
    return os;
}

class Test {
    Item a;
    Item b;
    Item c;

    public:
        Test() : a{5}, b{a+1}, c{b+1} { // a{5}, b{a+1}, c{b+1}, ,     c{b+1}, b{a+1}, a{5}   a{5}, b{6}, c{7},  c{7}, b{6}, a{5}
            cout << "a: " << a << " b: " << b << " c: " << c << endl;
        }

        Test(Item & _a, Item & _b, Item & _c) : a{_a}, b{a+1}, c{b+1} { // c{b+1}, b{a+1}, a{5} // a{_a}, b{a+1}, c{b+1}
            cout << "a: " << a << " b: " << b << " c: " << c << endl;
        }
};

int main() {

    //Test test;

    Item a{5}, b{a+1}, c{b+2};

    cout << "a: " << a << " b: " << b << " c: " << c << endl;
    cout << "---------------------" << endl;

    Test test(a,b,c);

    return 0;
}