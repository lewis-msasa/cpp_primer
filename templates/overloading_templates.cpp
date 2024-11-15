#include <iostream>
/*
OVERLOADING TEMPLATES
- function templates can be overloaded by other templates or nontemplate functions
*/
template <typename T>
void display(const T& value) {
    std::cout << "Single parameter: " << value << std::endl;
}

template <typename T, typename U>
void display(const T& value1, const U& value2) {
    std::cout << "Two parameters: " << value1 << " and " << value2 << std::endl;
}

//Nontemplate and Template Overloads


template <typename T>
void print(T value) {
    std::cout << "Template overload for generic type: " << value << std::endl;
}

void print(int value) {
   std::cout << "Template overload for generic type: " << value << std::endl;
}