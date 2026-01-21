#include <iostream>

#define MAX(a,b) (a < b) ? b : a

using namespace std;


int main() {

  int a = 5, b = 10;
  cout << "a is "
       << a
       << " and b is "
       << b
       << endl;
  int aa = a, bb = b;
  int a_save = a, b_save = b;  
  int m = MAX(a++,b++);
  int mm = max(aa++,bb++);
  
  cout << "max of  a = "
       << a_save
       << " and  b = "
       << b_save
       << " is "
       << m
       << " ?!?!"
       << endl;

  cout << "max of aa = "
       << a_save
       << " and bb = "
       << b_save
       << " is "
       << mm
       << " ?!?!"
       << endl;
  
  return 0;
}