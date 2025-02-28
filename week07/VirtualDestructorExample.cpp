#include <iostream>

class Base {
public:
    // Virtual destructor ensures proper cleanup
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; 
    return 0;
}
