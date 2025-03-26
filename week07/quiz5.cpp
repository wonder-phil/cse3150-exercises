#include <iostream>

using namespace std;

struct node {
    int data;
};

ostream & operator<<(ostream & os, const node & myNode) {
    os << "< " << myNode.data << " > ";

    return os;
}

void f(const node & n)  {
    n.data = 444;
    cout << "f: " << n << endl;
}

void g(node const & n) {
    n.data = 777;
    cout << "g: " << n << endl;
}

int main() {

    node a,b;
    a.data = 5;
    b.data = 999;

    f(a);
    g(b);

    return 0;
}