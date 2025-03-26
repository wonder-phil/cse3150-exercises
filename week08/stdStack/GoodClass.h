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
};

ostream & operator<<(ostream & os, const GoodClass & gc) {
    os  << gc.name 
        << " with int "
        << gc.value;

    return os;
}

#endif


//GoodClass(const GoodClass &) = delete;