#include <iostream>

using namespace std;

struct OnlyOne {

        int x, y;

        static OnlyOne *getInstance(int x, int y) { 
            if (nullptr == only_one) {
                only_one = new OnlyOne(x,y);
            } 
            return only_one; 
        }

        OnlyOne(const OnlyOne &)  = delete;
        void operator=(const OnlyOne &) = delete;
    
    private: 
        OnlyOne() {};
        OnlyOne(int x, int y) : x{x}, y{y} {};
        static OnlyOne* only_one; 
};

OnlyOne* OnlyOne::only_one = nullptr;

int main(){
    OnlyOne * o1 = OnlyOne::getInstance(9999,-5556);
    OnlyOne * o2 = OnlyOne::getInstance(-5,5);

    cout << o1->x << endl;
    cout << o2->x << endl;

    return 0;
}