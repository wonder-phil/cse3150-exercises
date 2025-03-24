#ifndef _STACKEMPTY_EXCEPTION_
#define _STACKEMPTY_EXCEPTION_

#include <string>

using namespace std;

class StackEmptyException : public std::exception {

    private:
        char * message;
    public:
        StackEmptyException(char * msg) : message(msg) { }

        char * getMessage() const { return message; }

        char * what();
};


#endif