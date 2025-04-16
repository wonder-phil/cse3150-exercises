#include <iostream>
#include <memory>


using namespace std;


struct Box {
  int a;
  Box(int x) { a = x; }
  ~Box() { cout << "Destrucing this instance of Box: " << this << endl; }
};



void test2() {
  using namespace std;
  shared_ptr<Box> p(new Box(3));

  cout << "p = " << p << " *p = " << (*(p.get())).a << endl;

  shared_ptr<Box> z;
  z = p;

  cout << "p = " << p << endl;
  cout << "z = " << z << " *z = " <<  endl;
  cout << "use_count (p) = " << p.use_count() << endl;
  cout << "use_count (z) = " << z.use_count() << endl;
}


int main() {

  using namespace std;

  test2();

  return 0;
}