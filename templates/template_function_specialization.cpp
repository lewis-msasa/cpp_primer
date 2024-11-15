#include <iostream>
#include <string>

template <typename T>
void print(const T& value) {
    std::cout << "General template: " << value << '\n';
}

// Full specialization for std::string
template <>
void print<std::string>(const std::string& value) {
    std::cout << "String specialization: " << value << '\n';
}

int main() {
    print(42);               // Uses general template
    print("Hello");          // Uses general template (const char*)
    print(std::string("Hi"));// Uses specialization for std::string
}