#include <iostream>
#include <memory>

using namespace std;

class Token {

    int id;

    public:
        int getId() const { return id; }
        Token(int v) : id{v} {}
};

ostream & operator<<(ostream & os, const Token & token) {
    os << token.getId();
    return os;
};

int main() {


  auto ptr = std::make_unique<Token>(42);

  cout << ptr->getId() << endl;

  return 0;
}