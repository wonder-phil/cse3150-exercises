#include <iostream>

using namespace std;

/* Not good !! */


class MyGoodClass {
    
    public:
        int x,y;
        MyGoodClass() : x{0}, y{0} {};
        MyGoodClass(int x, int y) : x{x}, y{y} {};

};

MyGoodClass & my_OK_fcn() {
    MyGoodClass mgc(-5,-9);
    MyGoodClass * ref = & mgc;

    return mgc;
}

MyGoodClass * my_other_fcn() {
    MyGoodClass mgc(7,8);

    return &  mgc;
}

int main() {

   
    MyGoodClass main_mgc = my_OK_fcn();

    cout <<  main_mgc.x << " " <<  main_mgc.y << endl;

    
    MyGoodClass * main_mgc_ptr = my_other_fcn();

    cout <<  main_mgc_ptr->x << " " <<  main_mgc_ptr->.y << endl;

   

    return 0;
}