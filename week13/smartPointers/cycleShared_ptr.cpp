#include <iostream>
#include <memory>

using namespace std;

struct Node {
    shared_ptr<Node> next;
    shared_ptr<Node> prev;  // Replace with weak_ptr to prevent cycle
};

int main() {
    auto a = make_shared<Node>();
    auto b = make_shared<Node>();

    a->next = b;
    b->prev = a;  // A cycle, Yipes!  Can weak_ptr-s rescue us?

    cout << "Use count of a: " << a.use_count() << endl;
    cout << "Use count of b: " << b.use_count() << endl;
}

/*
    Try:
Linux> valgrind ./a.out 

*/
