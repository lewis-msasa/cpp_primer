#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Display the point
    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    // Overload dereference operator (*)
    Point& operator*() {
        return *this; // Return reference to the object
    }

    // Overload arrow operator (->)
    Point* operator->() {
        return this; // Return pointer to the object
    }

    // Overload function call operator ()
    int operator()(int newX, int newY) {
        x = newX;
        y = newY;
        return x + y; // Return the sum of x and y
    }

    // Member function to add values (for pointer-to-member example)
    int add(int value) {
        return x + y + value;
    }

    // Output operator overload for convenience
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    // Initializing Point object
    Point p1(5, 10);

    // 1. Dereference operator (*)
    Point* ptr = &p1;
    std::cout << "Dereferenced object: " << *ptr << std::endl;

    // 2. Arrow operator (->)
    p1->display(); // Using overloaded arrow operator to call display

    // 3. Function call operator ()
    std::cout << "Setting new values using function call operator: ";
    int sum = p1(20, 30); // Setting x and y using function call
    std::cout << p1 << ", Sum = " << sum << std::endl;

    // 4. Pointer-to-member operator (.* and ->*)
    int (Point::*memberFunction)(int) = &Point::add; // Pointer to member function
    std::cout << "Using pointer-to-member with .*: " << (p1.*memberFunction)(15) << std::endl;

    std::cout << "Using pointer-to-member with ->*: " << (ptr->*memberFunction)(20) << std::endl;

    return 0;
}
