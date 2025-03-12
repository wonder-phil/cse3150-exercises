#include <ostream>

#include "HoldsDynamicArray.h"


using namespace std;


int main() {

    HoldsDynamicArray hda(10);
    cout << hda << endl;

    HoldsDynamicArray newHda(move(hda));

    cout << hda << endl;
    cout << newHda << endl;

    return 0;
}