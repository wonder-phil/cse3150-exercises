#include <iostream>

using namespace std;


struct Top {
    virtual void f() const { cout << "Top::f" << endl; }
    void g() const { cout << "Top::g" << endl; }
};

struct Middle : Top {
    void f() const { cout << "Middle::f" << endl; }
    void g() { cout << "Middle::g" << endl; }
};

struct Bottom : Middle {
    void f() { cout << "Bottom::f" << endl; }
    void g() const { cout << "Bottom::g" << endl; }
};

void call(const Top & top) {
    top.f();
    top.g();
}

int main() {
    Top top;
    Middle middle;
    Bottom bottom;
    
    call (top);
    cout << "----------" << endl;
    call (middle);
    cout << "----------" << endl;
    call (bottom);

    cout << "===============" << endl;

    top.f();
    top.g();

    cout << "----------" << endl;

    middle.f();
    middle.g();

    cout << "----------" << endl;

    bottom.f();
    bottom.g();


    return 0;
}