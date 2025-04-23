#include <iostream>
#include <memory>

using namespace std;

struct Node {
    shared_ptr<Node> next;
    weak_ptr<Node> prev;  // Replace with weak_ptr to prevent cycle
};

int main() {
    auto left = make_shared<Node>();
    auto right = make_shared<Node>();

    left->next = right;
    right->prev = left; 

    cout << "Use count of left: " << left.use_count() << endl;
    cout << "Use count of right: " << right.use_count() << endl;
}

/*
    Try:
Linux> valgrind ./a.out 

*/
