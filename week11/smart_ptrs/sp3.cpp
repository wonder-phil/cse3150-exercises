include <iostream>
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


void test1() {
  using namespace std;
  shared_ptr<int> p(new int);
  *p = 42;

  cout << "p = " << p << " *p = " << *p << endl;

  // shared_ptr<int> z(p);
  // shared_ptr<int> z = p;
  shared_ptr<int> z;
  z = p;

  cout << "p = " << p << endl;
  cout << "z = " << z << " *z = " << *z << endl;
  cout << "use_count (z): " << z.use_count() << endl;
}


void test2(const Foo & foo) {
  using namespace std;
  shared_ptr<Foo> p(new Foo(3));

  cout << "p = " << p << " *p = " << *p << endl;

  shared_ptr<Foo> z;
  z = p;

  cout << "p = " << p << endl;
  cout << "z = " << z << " *z = " << *z << endl;
  cout << "use_count (z): " << z.use_count() << endl;
}


int main() {

  using namespace std;

  test1();

  return 0;
}