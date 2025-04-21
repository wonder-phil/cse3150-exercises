#include <iostream>
#include <memory>
#include <string>

using namespace std;



struct Box {
    string name;

    Box(string name) : name{name} {}
    shared_ptr<Box> boxPtr; 
    
    ~Box() { cout << "Box destroyed" << endl; }
};


int main() {
    shared_ptr<Box> box = make_shared<Box>("Babe Ruth");
    
    {
        shared_ptr<Box> box1 = make_shared<Box>("Jackie Robinson");
        box->boxPtr = box1;
    }

    cout << "------------" << endl;
}

