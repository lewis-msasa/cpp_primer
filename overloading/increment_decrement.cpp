#include <iostream>

class Counter {
private:
    int value;

public:
    Counter() : value(0) {} // Default constructor
    Counter(int v) : value(v) {} // Parameterized constructor

    // Prefix increment (++c)
    Counter& operator++() {
        ++value; // Increment the value first
        return *this; // Return the modified object
    }

    // Postfix increment (c++)
    Counter operator++(int) {
        Counter temp = *this; // Store the current value in a temporary object
        ++value; // Increment the actual value
        return temp; // Return the original value (before increment)
    }

    // Prefix decrement (--c)
    Counter& operator--() {
        --value; // Decrement the value first
        return *this; // Return the modified object
    }

    // Postfix decrement (c--)
    Counter operator--(int) {
        Counter temp = *this; // Store the current value in a temporary object
        --value; // Decrement the actual value
        return temp; // Return the original value (before decrement)
    }

    // Overload the output operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Counter& c);
};

// Output operator overload
std::ostream& operator<<(std::ostream& os, const Counter& c) {
    os << c.value;
    return os;
}

int main() {
    Counter c(10); // Initialize with value 10

    std::cout << "Initial value: " << c << std::endl;

    // Prefix increment
    ++c;
    std::cout << "After prefix increment (++c): " << c << std::endl;

    // Postfix increment
    c++;
    std::cout << "After postfix increment (c++): " << c << std::endl;

    // Prefix decrement
    --c;
    std::cout << "After prefix decrement (--c): " << c << std::endl;

    // Postfix decrement
    c--;
    std::cout << "After postfix decrement (c--): " << c << std::endl;

    return 0;
}
