#include <iostream>
#include <memory>

template <typename T>
std::ostream & operator<<(std::ostream & os, std::unique_ptr<T> & p) {
  return os << p.get();
}

std::unique_ptr<int> foo(std::unique_ptr<int> z) {
  using namespace std;

  cout << "enter foo" << endl;
  cout << "z = " << z << " *z = " << *z << endl;
  cout << "exit foo" << endl;

  return std::move(z);
}

int main() {

  using namespace std;

  unique_ptr<int> p(new int), q(new int);
  *p = 42;


  p = foo(std::move(p));

  q = std::move( foo(std::move(p)) );  
  
  cout << "p = " << p << endl;
  cout << "q = " << q << endl;  


  return 0;
}