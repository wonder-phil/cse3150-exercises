#include <iostream>

using namespace std;

void update_string(string & myString) {
    for (int i=0; i < myString.size(); i++) {
        myString[i] = 'X';
    }
}

int main() {

    string aString = "Hello";

    cout << aString << endl;

    update_string(aString);

    cout << aString << endl;

    return 0;
}