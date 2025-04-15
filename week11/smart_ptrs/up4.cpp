#include <iostream>
#include <memory>

template <typename T>
std::ostream & operator<<(std::ostream & os, std::unique_ptr<T> & p) {
  return os << p.get();
}

void foo(std::unique_ptr<int> & z) {
  using namespace std;

  cout << "enter foo" << endl;
  cout << "z = " << z << " *z = " << *z << endl;
  cout << "exit foo" << endl;
}

int main() {

  using namespace std;

  unique_ptr<int> p(new int);
  *p = 42;


  foo(p);
  
  cout << "p = " << p << endl;


  return 0;
}