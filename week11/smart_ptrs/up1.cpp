#include <iostream>
#include <memory>

template <typename T>
std::ostream & operator<<(std::ostream & os, std::unique_ptr<T> & p) {
  return os << p.get();
}


int main() {
  using namespace std;

  unique_ptr<int> p(new int);
  *p = 42;
  
  cout << "p = " << p << " *p = " << *p << endl;
  unique_ptr<int> z(std::move(p));
  cout << "p = " << p << endl;
  cout << "z = " << z << " *z = " << *z << endl;

  return 0;
}