#include <iostream>
#include <stdexcept>

class MyException {
public:
    MyException(const char* msg) : message(msg) { }

    MyException(const MyException& other) : message(other.message) {
        std::cout << "Copy constructor called.\n";
    }

    MyException(MyException&& other) noexcept : message(other.message) {
        std::cout << "Move constructor called.\n";
    }
    const char* getMessage() const { return message; }
private:
    const char* message;
};

void f() {
    throw MyException("Error occurred");
}

int main() {
    try {
        f();
    } catch (const MyException& e) {  // Caught by const reference; no extra copy here
        std::cout << "Caught: " << e.getMessage() << "\n";
    }
    return 0;
}
