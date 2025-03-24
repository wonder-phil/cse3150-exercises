#ifndef _GOOD_CLASS_H
#define _GOOD_CLASS_H

#include <string>

using namespace std;

class GoodClass {

    friend ostream & operator<<(ostream & os, const GoodClass & gc);

        string name;
        int value;

    public:

        GoodClass(string _name, int _value) : name{_name}, value{_value} {}
        GoodClass() {};

        GoodClass(const GoodClass & gc) : name{gc.name}, value{gc.value} {
            cout << "Copy constructor called!" << endl;
        }
};

ostream & operator<<(ostream & os, const GoodClass & gc) {
    os  << gc.name 
        << " with int "
        << gc.value;

    return os;
}

#endif


//GoodClass(const GoodClass &) = delete;