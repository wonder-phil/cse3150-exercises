#include <iostream>
#include <cstring>

#include "MyString.h"

using namespace std;

ostream & operator<<(ostream & os, const MyString & myString) {
    if (myString.size > 0) {
        os << myString.data; 
    }
    os << " starts in memory location: "
       << static_cast<const void *>(myString.data) ;

    return os;
}

MyString::MyString(const char * str) {
    size = strlen(str);
    data = new char[size+1];
    memcpy(data, str, size+1);
}

MyString::MyString(const MyString & other) : size{other.size} {
    cout << "Copy constructor " << endl;
    if (size > 0) {
        data = new char[size+1];
        memcpy(data, other.data, size+1);
    }
}

MyString::MyString(MyString && other) {
    cout << "Move constructor" << endl;
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

MyString & MyString::operator=(MyString && other) noexcept {
    cout << "Move operator= " << endl;
    if (this != & other) {  

        delete [] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}


MyString::~MyString() {
    delete [] data;
}

