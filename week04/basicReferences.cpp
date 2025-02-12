#include <iostream>

int main() {
 using namespace std;

 int x = 99;
 const int &y = x;
 cout << "x = " << x << endl;
 cout << "y = " << y << endl;

 //y = -5;
 x = -5;

 cout << "x = " << x << endl;
 cout << "y = " << y << endl;
 cout << "&x = " << &x << endl;
 cout << "&y = " << &y << endl;
 return 0;
}
