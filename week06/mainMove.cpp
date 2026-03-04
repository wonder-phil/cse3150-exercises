#include <iostream>
#include <string>

using namespace std;


int main() {

    string myName = "Phil";

    cout << myName << endl;

    cout << "---Move---" << endl;

    move(myName) = "SuperMan";

    cout << myName << endl;


    /*
     * 
     */

    string s, t = "Great day!";


    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    cout << "---Move---" << endl;
    s = move(t);

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    return 0;
}