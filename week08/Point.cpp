#include <iostream>

class Point {
public:
    int x, y;

    // Constructor
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Overloading the + operator
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    // Function to display the point
    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    Point p3 = p1 + p2;  // Using overloaded operator+

    std::cout << "p1: "; p1.display();
    std::cout << "p2: "; p2.display();
    std::cout << "p3 (p1 + p2): "; p3.display();

    return 0;
}
