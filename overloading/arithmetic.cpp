#include <iostream>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // Default constructor
    Point(int x, int y) : x(x), y(y) {} // Parameterized constructor

    // Overload the plus operator (+) for point addition
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Overload the minus operator (-) for point subtraction
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    // Overload the multiply operator (*) for scaling by a scalar value
    Point operator*(int scalar) const {
        return Point(x * scalar, y * scalar);
    }

    // Overload the division operator (/) for scaling down by a scalar value
    Point operator/(int scalar) const {
        if (scalar == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return *this; // Return the current object unchanged
        }
        return Point(x / scalar, y / scalar);
    }

    // Overload the output operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

// Output operator overload
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(2, 3);
    Point p2(4, 6);

    // Point addition
    Point p3 = p1 + p2;
    std::cout << "p1 + p2 = " << p3 << std::endl;

    // Point subtraction
    Point p4 = p2 - p1;
    std::cout << "p2 - p1 = " << p4 << std::endl;

    // Multiplication by scalar
    Point p5 = p1 * 3;
    std::cout << "p1 * 3 = " << p5 << std::endl;

    // Division by scalar
    Point p6 = p2 / 2;
    std::cout << "p2 / 2 = " << p6 << std::endl;

    // Attempt division by zero
    Point p7 = p2 / 0; // Should print an error

    return 0;
}
