#include <iostream>
#include <memory>

using namespace std;

struct Right;

struct Left {
    string name;

    Left(string name) : name{name} {}
    shared_ptr<Right> rightPtr; 
    
    ~Left() { cout << "Left destructed" << endl; }
};

struct Right {
   string name;

   Right(string name) : name{name}{}
   weak_ptr<Left> leftWeakPtr;

   ~Right() { cout << "Right destructed" << endl; }
};


int main() {
    shared_ptr<Left>   left = make_shared<Left>("Babe Ruth");
    shared_ptr<Right> right = make_shared<Right>("Jackie Robinson");

    left->rightPtr = right;
    right->leftWeakPtr = left;

    cout << "Use count of left: " << left.use_count() << endl;
    cout << "Use count of right: " << right.use_count() << endl;
}

/*
    Try:
Linux> valgrind ./a.out 

*/
