#include <iostream>

using namespace std;

int main() {

    int i = -1;
    int const ic = -2; // read-only
    const int ci = -3; // read-only - same as above
    const int const ici = -4; // read-only - same as above
    
    cout << "i: " << i << endl;
    cout << "ic: " << ic << endl;
    cout << "ici: " << ici << endl;

    ic = 1111;
    ci = 88;
    ici = 987;

    return 0;
}