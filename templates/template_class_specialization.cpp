#include <iostream>
#include <string>

template <typename T>
class Printer {
public:
    void print(const T& value) {
        std::cout << "General template: " << value << '\n';
    }
};

// Full specialization for std::string
template <>
class Printer<std::string> {
public:
    void print(const std::string& value) {
        std::cout << "String specialization: " << value << '\n';
    }
};

int main() {
    Printer<int> intPrinter;
    Printer<std::string> stringPrinter;

    intPrinter.print(42);              // Uses general template
    stringPrinter.print("Hello");       // Uses specialized template for std::string
}
