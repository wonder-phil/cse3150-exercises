#ifndef __MY_STRING_H
#define __MY_STRING_H

#include <iostream>
#include <vector>


using namespace std;

class MyString {
    
    private:

        char * data;
        int size;

        friend ostream & operator<<(ostream & os, const MyString & myString);

    public:

        MyString(const char * str);
        MyString(const MyString & other);
        MyString(MyString && other);
        MyString &operator=(MyString && other) noexcept ;
        ~MyString();
};


#endif
