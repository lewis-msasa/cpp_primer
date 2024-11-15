#include <iostream>
#include <type_traits>

/*
Partial specialization allows customizing a class template based on part of its template parameters. 
It’s typically used when a template class has multiple parameters, and you want special behavior based on one of them.

*/

template <typename T>
class TypeChecker {
public:
    void checkType() {
        std::cout << "General type\n";
    }
};

// Partial specialization for pointer types
template <typename T>
class TypeChecker<T*> {
public:
    void checkType() {
        std::cout << "Pointer type\n";
    }
};

int main() {
    TypeChecker<int> intChecker;
    TypeChecker<int*> intPtrChecker;

    intChecker.checkType();     // Output: General type
    intPtrChecker.checkType();  // Output: Pointer type
}
