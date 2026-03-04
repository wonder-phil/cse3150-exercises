#include <iostream>

using namespace std;

int main() {

    int x = 10;
    const int &y = x;

    x = -99;

    cout << "y = " << y << endl;
    cout << "x = " << x << endl;


    x = -30;

    cout << "y = " << y << endl;
    cout << "x = " << x << endl;

    return 0;
}