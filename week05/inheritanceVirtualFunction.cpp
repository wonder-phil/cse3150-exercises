#include <iostream>

using namespace std;

struct Top {
    void virtual myFunction() { cout << "Top myFunction" << endl;}
};

struct Bottom : Top {
    void myFunction() override { cout << "Bottom myFunction" << endl;}
    void hello() { cout << "Hello !" << endl; }
};

int main() {
    Top top;

    top.myFunction();

    Top * bPtr = new Bottom();

    bPtr->myFunction();
    
    dynamic_cast<Bottom *>(bPtr)->hello();
    
    return 0;
}