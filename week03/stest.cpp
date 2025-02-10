#include <iostream>


using namespace std;


struct bigStruct {

    int big;
    struct littleStruct {
        int little;

    };

    littleStruct lStruct;

};

int main() {

    bigStruct bStruct;
    bStruct.lStruct.little = 9;

    return 0;
}