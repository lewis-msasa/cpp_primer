#include <iostream>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // Default constructor
    Point(int x, int y) : x(x), y(y) {} // Parameterized constructor

    // Friend function to overload the '<<' operator for output
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    // Friend function to overload the '>>' operator for input
    friend std::istream& operator>>(std::istream& is, Point& p);
};

// Overloading the '<<' operator
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// Overloading the '>>' operator
std::istream& operator>>(std::istream& is, Point& p) {
    std::cout << "Enter x: ";
    is >> p.x;
    std::cout << "Enter y: ";
    is >> p.y;
    return is;
}

int main() {
    Point p1;
    
    // Using overloaded '>>' to take input
    std::cin >> p1;
    
    // Using overloaded '<<' to output the point
    std::cout << "The point is: " << p1 << std::endl;
    
    return 0;
}
