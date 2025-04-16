#include <iostream>
#include <memory>

using namespace std;

template <typename T>
std::ostream & operator<<(std::ostream & os, std::shared_ptr<T> & p) {
  return os << p.get();
}

struct Box {
  int val;
  Box(int v) : val(v) {}
};

class Wrapper {

  Box * b;
  public:
    Wrapper(int x) : b(new Box(x)) {}

    Box & operator*() { return *b; }

    ~Wrapper() { delete b; }
};

int main() {
  Wrapper w(-99);
  cout << (*w).val << endl;  // prints 100
}

