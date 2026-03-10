#include <iostream>

#include "Bottom.h"


using namespace std;

int main() {
    
    Top *top = new Bottom();
    Top *top_middle = new Middle();
    
    top->function();
    top_middle->function();

    delete top;
    delete top_middle;
    

    return 0;
}