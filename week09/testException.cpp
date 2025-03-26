#include <iostream>
#include <stdexcept>

class MyException {
public:
    MyException(const char * msg) : message(msg) { }

    const char* getMessage() const { return message; }
private:
    const char* message;
};

int main() {
    try {
        f();
    } catch (const MyException & e) {
        std::cout << "Caught: " << e.getMessage() << "\n";
    }
    return 0;
}
