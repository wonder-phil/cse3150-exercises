#include <iostream>
#include <memory>

template <typename T>
std::ostream & operator<<(std::ostream & os, std::shared_ptr<T> & p) {
  return os << p.get();
}


struct Foo {
  int a;
  Foo(int x) { a = x; }
  // A descructor
  ~Foo() { std::cout << "Destrucing this instance of Foo: " << this << std::endl; }
};



void test2() {
  using namespace std;
  shared_ptr<Foo> p(new Foo(3));

  cout << "p = " << p << " *p = " << endl;

  shared_ptr<Foo> z;
  z = p;

  cout << "p = " << p << endl;
  cout << "z = " << z << " *z = " <<  endl;
  cout << "use_count (z): " << z.use_count() << endl;
}


int main() {

  using namespace std;

  test2();

  return 0;
}