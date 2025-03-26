#include <iostream>
#include <stack>

using namespace std;

class GoodClass {

        friend ostream & operator<<(ostream & os, const GoodClass & gc);

        string name;
        int score;

    public:

        GoodClass(string _name, int _score): name{_name}, score{_score} { }
        GoodClass(const GoodClass & gc) : name{gc.name}, score{gc.score} {
            cout << "Copy Constructor" << endl;
        }

};

class NonCopyableClass {

    friend ostream & operator<<(ostream & os, const NonCopyableClass & ncc);

    string name;
    int score;

public:

    NonCopyableClass(string _name, int _score): name{_name}, score{_score} { }

    NonCopyableClass(const NonCopyableClass & gc) = delete;

};

ostream & operator<<(ostream & os, const GoodClass & gc) {
    os  << "Name: " 
        << gc.name
        << " score:"
        << gc.score;

    return os;
}


ostream & operator<<(ostream & os, const NonCopyableClass & ncc) {
    os  << "Name: " 
        << ncc.name
        << " score:"
        << ncc.score;

    return os;
}

int main() {
    stack<GoodClass> goodStack;

    stack<NonCopyableClass> nonCopyableClassStack;

    GoodClass gc1("Grace", 100);
    GoodClass gc2("Alan", 99);
    GoodClass gc3("Ada", 99);
    GoodClass gc4("Charles", 89);

    cout << "---push-uses-copy-constructor-START------" << endl;
    goodStack.push(gc1);
    goodStack.push(gc2);
    goodStack.push(gc3);
    goodStack.push(gc4);
    cout << "---push-uses-copy-constructor-END------" << endl;

    NonCopyableClass ncc1("Richard", 99);
    NonCopyableClass ncc2("Max", 100);

    //nonCopyableClassStack.push(ncc1);
    //nonCopyableClassStack.push(ncc2);

    while (! nonCopyableClassStack.empty() ) {
        cout << nonCopyableClassStack.top() << endl;
        nonCopyableClassStack.pop();
    }

    while (! goodStack.empty()) {
        cout << goodStack.top() << endl;
        goodStack.pop();
    }

}
