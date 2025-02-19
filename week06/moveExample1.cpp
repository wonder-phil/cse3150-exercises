#include <iostream>


using namespace std;

int main() {

    string s = "Hello!";
    cout << "s = " << s << endl;
    move(s) = "good day";
    cout << "s = " << s << endl;
    
    string t, u = "Super Star!";
    cout << "t = " << t << endl;
    cout << "u = " << u << endl;
    t = move(u);
    cout << "t = " << t << endl;
    cout << "u = " << u << endl;

    return 0;
}