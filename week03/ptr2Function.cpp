
#include <iostream>

using namespace std;

#include <iostream>

// A function that takes an int and returns an int.
int square(int x) {
    return x * x;
}

// myFunction expects a pointer to a function that takes an int and returns an int.
int myFunction(int (*func)(int)) {
    // Call the function pointer with a test value.
    return func(5);
}

int main() {
    // Pass the function 'square' to myFunction.
    int result = myFunction(square);
    std::cout << "Result: " << result << std::endl;
    return 0;
}