#include <iostream>
#include <memory>
#include <string>

using namespace std;


struct Node {
    string name;

    Node(string name) : name{name} {}
    weak_ptr<Node> wpNext;  // weak_ptr!!
    shared_ptr<Node> spNext;
    
    ~Node() { cout << "Node [" << name << "] destructor" << endl; }
};



int main() {

    string names[] = { "zero", "one", "two", "three", "four", "five" };
    int numberOfNodes = sizeof(names)/sizeof(names[0]);

    shared_ptr<Node> root = make_shared<Node>(names[0]);
    shared_ptr<Node> node = root;

    for (int i=1; i < numberOfNodes; i++) {
        node->spNext = make_shared<Node>(names[i]);
        node->wpNext = node->spNext;
        node = node->spNext;
    }
    //node->spNext = root;
    //node->wpNext = root;
    
    node = root;
    for (int i=0;  i < numberOfNodes; i++) {
        cout << "[" << node.get()->name << "] : use_count: " << node.use_count() << endl;
        node = node->spNext;
    } 

    cout << "--------------" << endl;

    node = root;
    for (int i=0;  i < numberOfNodes; i++) {
        cout << "[" << node.get()->name << "] : use_count: " << node.use_count() << endl;
        node->wpNext = node->spNext;
        node = node->spNext;
    } 

    cout << "--------------" << endl;

    node = root;
    for (int i=0;  i < numberOfNodes; i++) {
        cout << "[" << node.get()->name << "] : use_count: " << node.use_count() << endl;
        if (auto ptr = node->wpNext.lock()) {
            node->wpNext = ptr; //node->spNext;
            node = ptr;
        } else {
            cerr << "Ouch ! Expired WeakPtr" << endl;
        }
        
    } 
    

    cout << "root.use_count(): " << root.use_count() << endl;
}