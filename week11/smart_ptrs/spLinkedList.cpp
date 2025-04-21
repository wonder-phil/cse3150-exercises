#include <iostream>
#include <memory>
#include <string>

using namespace std;


struct Node {
    string name;

    Node(string name) : name{name} {}
    shared_ptr<Node> next; 
    
    ~Node() { cout << "Node [" << name << "] destructor" << endl; }
};



int main() {

    string names[] = { "one", "two", "three", "four", "five" };
    int numberOfNodes = sizeof(names)/sizeof(names[0]);


    shared_ptr<Node> root = make_shared<Node>(names[0]);
    shared_ptr<Node> node = root;

    for (int i=1; i < numberOfNodes; i++) {
        node->next = make_shared<Node>(names[i]);
        node = node->next;
    }

    node = root;
    for (int i=0;  i < numberOfNodes; i++) {
        cout << "[" << node.get()->name << "]" << endl;
        node = node->next;
    } 
}

