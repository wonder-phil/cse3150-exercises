#include <iostream>

using namespace std;

struct OnlyOneStackFrame {

        int x, y;

        static OnlyOneStackFrame & getInstance(int x, int y) { 
            static OnlyOneStackFrame _instance(x,y);
            return _instance; 
        }

        OnlyOneStackFrame(const OnlyOneStackFrame &)  = delete;
        void operator=(const OnlyOneStackFrame &) = delete;
    
    private: 
        
        OnlyOneStackFrame() {};
        OnlyOneStackFrame(int x, int y) : x{x}, y{y} {};
         
};



int main(){
    OnlyOneStackFrame & o1 = OnlyOneStackFrame::getInstance(9999,-5556);
    OnlyOneStackFrame & o2 = OnlyOneStackFrame::getInstance(-5,5);

    cout << o1.x << endl;
    cout << o2.x << endl;

    return 0;
}