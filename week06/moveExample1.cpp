#include <iostream>


using namespace std;

int main() {

    string s = "Hello!";
    move(s) = "good day";
    cout << "s = " << s << endl;
    
    string t, u = "Super Star!";
    t = move(u);
    cout << "t = " << t << endl;
    cout << "u = " << u << endl;

    return 0;
}