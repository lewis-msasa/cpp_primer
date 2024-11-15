#include <iostream>
#include <string>

template <typename T>
class Printer {
public:
    void print(const T& value) {
        std::cout << "General template: " << value << '\n';
    }
};

// Specialization of `print` for `std::string`
template <>
void Printer<std::string>::print(const std::string& value) {
    std::cout << "String specialization: " << value << '\n';
}

int main() {
    Printer<int> intPrinter;
    Printer<std::string> stringPrinter;

    intPrinter.print(42);               // Uses general template
    stringPrinter.print("Hello");        // Uses specialization for std::string
}
