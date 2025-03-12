#include <iostream>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
    Point(double _x, double _y) : x{_x}, y{_y} {}
};

class Shape {
    private:
        double areaShoelace(const vector<Point> & points) {
            double sum1 = 0.0, sum2 = 0.0;
            int n = points.size();
            for (int i = 0; i < n; i++) {
                int j = (i + 1) % n; // next vertex (wrapping around)
                sum1 += points[i].x * points[j].y;
                sum2 += points[i].x * points[j].y;
            }
            return 0.5 * abs(sum1 - sum2);
        }

    public:
        vector<Point> points;
        Shape() {}
        
        virtual double area() { return areaShoelace(points); }; 
        //virtual ~Shape() {}
};

class Rectangle : public Shape {

    public:
        Rectangle() {}
        Rectangle(const vector<Point> & _points) {
            points = _points;
        }
        
        virtual double area() override {
            cout << "Rectangle area" << endl;

            return 0.0;
        }
};

class Square : public Rectangle {
    public:
        Square() {}
        Square(const vector<Point> & _points) {
            points = _points;
        }
        double area() override {
            cout << "Square area" << endl;

            return 0.0;
        }
};

int main() {

    vector<Point> rectangle = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };

    Rectangle r(rectangle);
    cout << "r area: " << r.area() << endl;

    vector<Point> square = { {0, 0}, {4, 0}, {4, 4}, {0, 4} };
    Square s(square);
    cout << "s area: " << s.area() << endl;

    return 0;
}