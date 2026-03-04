#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <cstring>

using namespace std;

class MyString {

    char * data;
    int size;

public:
    MyString() : data{nullptr}, size{0} {}

    MyString(const MyString & other) : size{other.size} {
        if (size > 0) {
            data = new char[size+1];
            memcpy(data, other.data, size+1);
        }
    }

    MyString(char * stringPtr, int _size) : size{_size} {
        if (size > 0) {
            data = new char[size+1];
            memcpy(data, stringPtr, size+1);
        }
    }

    MyString(MyString && old) {
        data = old.data;
        size = old.size;

        old.data = nullptr;
        old.size = 0;
    }

    MyString & operator=(MyString && right) {
        if (this == & right) {
            return *this;
        } else {
            data = right.data;
            size = right.size;

            right.data = nullptr;
            right.size = 0;
        }
    }

    friend ostream & operator<<(ostream & os, const MyString & myString);


};

ostream & operator<<(ostream & os, const MyString & myString) {
    if (myString.size > 0) {
        for (int i = 0; i < myString.size; i++) {
            os << myString.data[i];
        }
    } 

    return os;
}

#endif

