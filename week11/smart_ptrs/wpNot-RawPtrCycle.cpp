#include <iostream>
#include <memory>
#include <string>

using namespace std;


struct Right;


struct Left {
    string name;

    Left(string name) : name{name} {}
    Right * rightPtr; 
    
    ~Left() { cout << "Left destroyed" << endl; }
};

struct Right {
   string name;

   Right(string name) : name{name}{}
   Left * leftPtr;

   ~Right() { cout << "Right destroyed" << endl; }
};



int main() {
    Left * left = new Left("Babe Ruth");
    Right * right = new Right("Jackie Robinson");

    left->rightPtr = right;
    right->leftPtr = left;  

    delete left;
    delete right;
}

