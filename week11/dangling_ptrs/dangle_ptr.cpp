#include <iostream>

using namespace std;

/* Not good !! */


int & my_first_fcn() {
    int val = 222;
    int * ref = & val;

    return *ref;
}

int & getRef_yipes() {
    int x = 42;
    return x; 
}


int * my_other_fcn() {
    int val = 99;

    return & val;
}

int main() {

    int x = my_first_fcn();
    cout << x << endl;
    
    int y = getRef_yipes();
    cout << y << endl;

    int * z = my_other_fcn();
    cout << z << endl;

    return 0;
}