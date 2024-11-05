#include <iostream>
#include <stdexcept> // For exceptions

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // Default constructor
    Point(int x, int y) : x(x), y(y) {} // Parameterized constructor

    // Overload the subscript operator for non-const access
    int& operator[](int index) {
        if (index == 0) {
            return x; // Return reference to x
        } else if (index == 1) {
            return y; // Return reference to y
        } else {
            throw std::out_of_range("Index out of range. Use 0 for x or 1 for y.");
        }
    }

    // Overload the subscript operator for const access
    int operator[](int index) const {
        if (index == 0) {
            return x; // Return x value
        } else if (index == 1) {
            return y; // Return y value
        } else {
            throw std::out_of_range("Index out of range. Use 0 for x or 1 for y.");
        }
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
    Point p1(3, 5);

    // Access elements using subscript notation
    std::cout << "p1[0] = " << p1[0] << std::endl; // Access x
    std::cout << "p1[1] = " << p1[1] << std::endl; // Access y

    // Modify elements using subscript notation
    p1[0] = 7; // Modify x
    p1[1] = 9; // Modify y

    std::cout << "After modification, p1 = " << p1 << std::endl;

    // Attempt to access an invalid index (should throw an exception)
    try {
        std::cout << "p1[2] = " << p1[2] << std::endl; // Invalid index
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
