#include <iostream>
#include <memory>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
  auto shared = make_shared<int>(), shared2 = shared, shared3 = shared2;

  auto weak = weak_ptr<int>{shared};

  cout  << std::boolalpha
        << "shared.use_count(): " << shared.use_count() << '\n'
        << "weak.use_count(): " << weak.use_count() << '\n'
        << "weak.expired(): " << weak.expired() << '\n';

  weak.reset();

  cout  << "weak.reset();\n"
        << "shared.use_count(): " << shared.use_count() << '\n'
        << "weak.use_count(): " << weak.use_count() << '\n'
        << "weak.expired(): " << weak.expired() << '\n';
}


