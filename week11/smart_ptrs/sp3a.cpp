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

template<typename T>
class Wrapper {

  int useCount = 0;

  T * b;
  public:
    Wrapper(int x) : b(new T(x)), useCount{1} { }

    Wrapper & operator=(const Wrapper & wrapper) {
      if (this != & wrapper) {
        useCount++;
        
      }
      return *this;
    }

    int use_count() { return useCount; }

    T & operator*() { return * b; }

    ~Wrapper() { delete b; }
};

int main() {
  Wrapper<Box> w(-99), w2(0);
  w2 = w;
  cout << "use count: " << w2.use_count() << endl;

  cout << (*w).val << endl;  // prints 100
}

