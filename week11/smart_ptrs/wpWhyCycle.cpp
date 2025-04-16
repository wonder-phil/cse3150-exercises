#include <iostream>
#include <memory>
#include <string>

using namespace std;


struct Right;


struct Left {
    string name;

    Left(string name) : name{name} {}

    shared_ptr<Right> rightPtr; 
    
    ~Left() { cout << "Left destroyed" << endl; }
};

struct Right {
   string name;

   Right(string name) : name{name}{}
   shared_ptr<Left> leftPtr;

   ~Right() { cout << "Right destroyed" << endl; }
};



int main() {
    shared_ptr<Left> left = make_shared<Left>("Babe Ruth");
    shared_ptr<Right> right = make_shared<Right>("Jackie Robinson");

    {
    left->rightPtr = right;
    right->leftPtr = left;  // uses weak_ptr, avoids memory leak
    }

    cout << "------------" << endl;

    
}

