#include <iostream>

#define FCN(x)  { x++; };

using namespace std;

int main() {

  int a = 5, b = 10;

  FCN(a)
  FCN(b)
  FCN(a+b)

  cout << "a is "
       << a
       << " and b is "
       << b
       << endl;

  return 0;
}

