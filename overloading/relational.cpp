#include <iostream>
#include <cmath> // For sqrt

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {} // Default constructor
    Point(int x, int y) : x(x), y(y) {} // Parameterized constructor

    // Calculate Euclidean distance from the origin (0, 0)
    double distance() const {
        return std::sqrt(x * x + y * y);
    }

    // Overload the '==' operator
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // Overload the '!=' operator
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // Overload the '<' operator
    bool operator<(const Point& other) const {
        return this->distance() < other.distance();
    }

    // Overload the '>' operator
    bool operator>(const Point& other) const {
        return this->distance() > other.distance();
    }

    // Overload the '<=' operator
    bool operator<=(const Point& other) const {
        return this->distance() <= other.distance();
    }

    // Overload the '>=' operator
    bool operator>=(const Point& other) const {
        return this->distance() >= other.distance();
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
    Point p1(3, 4); // Distance from origin = 5
    Point p2(6, 8); // Distance from origin = 10
    Point p3(3, 4); // Same as p1

    // Compare equality
    std::cout << "p1 == p2: " << (p1 == p2) << std::endl;
    std::cout << "p1 == p3: " << (p1 == p3) << std::endl;

    // Compare inequality
    std::cout << "p1 != p2: " << (p1 != p2) << std::endl;

    // Less than, greater than
    std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
    std::cout << "p1 > p2: " << (p1 > p2) << std::endl;

    // Less than or equal, greater than or equal
    std::cout << "p1 <= p2: " << (p1 <= p2) << std::endl;
    std::cout << "p1 >= p3: " << (p1 >= p3) << std::endl;

    return 0;
}
