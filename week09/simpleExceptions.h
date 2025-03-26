#ifndef _SIMPLE_EXCEPTION_
#define _SIMPLE_EXCEPTION_

#include <string>

using namespace std;

class StackEmptyException : public std::exception {

    private:

        char * message;

    public:
        StackEmptyException(char * msg) : message{msg} { }
        char * what();
        char * getMessage() const {  return message; }
};


#endif