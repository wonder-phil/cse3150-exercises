#ifndef _STACKEMPTY_EXCEPTION_
#define _STACKEMPTY_EXCEPTION_

#include <string>
#include <cstring>

using namespace std;

class StackEmptyException : public std::exception {

    private:

        char * message;

    public:
        StackEmptyException(char * msg) {
            cerr << "CONSTRUCTOR" << endl; 
            message = new char[strlen(msg)];
            memcpy(message, msg, strlen(msg));
        }

        char * what();

        char * getMessage() const {  return message; }

        ~StackEmptyException() { 
            delete [] message;
        }
};


#endif