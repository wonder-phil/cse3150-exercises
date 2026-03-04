#include <iostream>
#include <string>

#include "MyString.h"

using namespace std;


int main() {

    char strExample[] = "Hello - what a great day!";
    MyString myString(strExample, sizeof(strExample)+1);

    cout << myString << endl;

    return 0;
}