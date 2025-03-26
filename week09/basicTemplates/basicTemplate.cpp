#include <iostream>

using namespace std;


template<typename T>
T my_max(const T & x, const T & y) {
    return ( x > y) ? x : y;
}

int main() {

    int i = my_max(3,7);
    cout << "max of 3,7 is " << i << endl;

    double d = my_max(3.99,7.35);
    cout << "max of 3.99 ,7.35 is " << d << endl;

    return 0;
}