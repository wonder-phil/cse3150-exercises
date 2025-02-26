#include <iostream>
#include <vector>

#include "MyString.h"

using namespace std;


int main() {

        MyString a("Hello great wonderful world!");
        MyString b = a;
        
        cout << "a: " << a << endl;
        cout << "b: "<< b << endl;

        MyString c = move(b);

        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;

        MyString d("Good day!");

        d = move(a);

        cout << "a: " << a << endl;
        cout << "d: " << d << endl;

    return 0;
}