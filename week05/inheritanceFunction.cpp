#include <iostream>

using namespace std;

struct Top {
    void myFunction() { cout << "Top myFunction" << endl;}
};
struct Bottom : Top {
    void myFunction() { cout << "Bottom myFunction" << endl;}
};

int main() {
    Bottom bottom;
    bottom.myFunction();
    cout << "-----------" << endl;

    bottom.Top::myFunction();
    
    return 0;
}