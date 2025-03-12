#ifndef _MY_W_STACK_
#define _MY_W_STACK_

using namespace std;

template<typename T, int TOTAL_SIZE>
class MyWStack {
    int _size;
    
    T myArray[TOTAL_SIZE];

    public:

        void push(T e) {
            myArray[_size++] = e;
        }

        void pop() {
            _size--;
        }

        T top() {
            return myArray[_size -1];
        }

        bool empty() {
            if (0 == _size) {
                return true;
            } else {
                return false;
            }
        }

        int size() const {
            return _size;
        }
        
        MyWStack() : _size{0} {}

};

#endif