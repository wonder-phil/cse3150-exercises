#include <iostream>

using namespace std;

int main() {

    int x = 10;
    int * z = new int;
    *z = -99;

    cout << *z << endl;
    cout << static_cast<void *>(z) << endl;

    int &y = x;

    cout << "y = " << y << endl;
    cout << "x = " << x << endl;


    y = -30;

    cout << "y = " << y << endl;
    cout << "x = " << x << endl;

    return 0;
}