#include <iostream>
#include <memory>
#include <string>

using namespace std;


class Child;  

class Parent {
public:
    string name;
    shared_ptr<Child> child;

    Parent(const string & name) : name(name) {
        cout << "Parent " << name << " created.\n";
    }

    ~Parent() {
        cout << "Parent " << name << " destroyed.\n";
    }
};

class Child {
public:
    string name;
    weak_ptr<Parent> parent; 

    Child(const string & name) : name(name) {
        cout << "Child " << name << " created.\n";
    }

    ~Child() {
        cout << "Child " << name << " destroyed.\n";
    }

    void showParent() {
        if (auto p = parent.lock()) {
            cout << "Child's parent is: " << p->name << "\n";
        } else {
            cout << "Parent is expired.\n";
        }
    }
};

int main() {
    shared_ptr<Parent> p = make_shared<Parent>("Alice");
    shared_ptr<Child> c = make_shared<Child>("Bob");

    p->child = c;
    c->parent = p;  // uses weak_ptr, avoids memory leak

    c->showParent();
}

