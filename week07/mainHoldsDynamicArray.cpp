#include <ostream>

#include "HoldsDynamicArray.h"


using namespace std;


int main() {

    HoldsDynamicArray hda(10), oHda;
    cout << hda << endl;

    HoldsDynamicArray newHda(move(hda));

    cout << hda << endl;
    cout << newHda << endl;

    oHda = move(newHda);

    cout << oHda << endl;
    cout << newHda << endl;


    return 0;
}