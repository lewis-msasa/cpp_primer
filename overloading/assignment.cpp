#include <iostream>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // Default constructor
    Point(int x, int y) : x(x), y(y) {} // Parameterized constructor

    // Overload the assignment operator '='
    Point& operator=(const Point& other) {
        if (this == &other) {
            return *this; // Check for self-assignment
        }
        x = other.x;
        y = other.y;
        return *this; // Return *this to allow for chain assignment
    }

    // Overload the '+=' operator for point addition
    Point& operator+=(const Point& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Overload the '-=' operator for point subtraction
    Point& operator-=(const Point& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // Overload the '*=' operator for scalar multiplication
    Point& operator*=(int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // Overload the '/=' operator for scalar division
    Point& operator/=(int scalar) {
        if (scalar == 0) {
            std::cerr << "Error: Division by zero!" << std::endl;
            return *this; // Return current object unchanged
        }
        x /= scalar;
        y /= scalar;
        return *this;
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

    // Assignment operator
    Point p3;
    p3 = p1;
    std::cout << "After assignment, p3 = " << p3 << std::endl;

    // Compound assignment operators
    p1 += p2;
    std::cout << "After p1 += p2, p1 = " << p1 << std::endl;

    p1 -= p2;
    std::cout << "After p1 -= p2, p1 = " << p1 << std::endl;

    p1 *= 2;
    std::cout << "After p1 *= 2, p1 = " << p1 << std::endl;

    p1 /= 2;
    std::cout << "After p1 /= 2, p1 = " << p1 << std::endl;

    return 0;
}
