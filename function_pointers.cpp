#include <iostream>
using namespace std;

// Function that adds two numbers
int add(int a, int b) {
    return a + b;
}

// Function that matches the signature
void sayHello() {
    cout << "Hello, World!" << endl;
}

// Function pointer type definition
typedef int (*Operation)(int, int);

// Function that takes a function pointer and two integers
int calculate(Operation op, int x, int y) {
    return op(x, y);  // Calls the function pointed to by op
}

// Function that takes a function pointer as a parameter
void executeFunction(void (*func)()) {
    func();  // Call the function pointed to by func
}

int main() {
    Operation addPtr = &add;  // Declare and initialize the function pointer
    int result = calculate(addPtr, 5, 10);  // Use the function pointer
    cout << "Result: " << result << endl;  // Outputs: Result: 15


     // Declaration and initialization of a function pointer
    void (*functionPtr)() = &sayHello;
    // Calling the function through the pointer
    functionPtr();  // Outputs: Hello, World!
    // Passing a function pointer to another function
    executeFunction(sayHello);


    return 0;
}
