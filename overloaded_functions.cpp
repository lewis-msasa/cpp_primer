#include <iostream>
using namespace std;

// Overloaded functions
void print(int i) {
    cout << "Integer: " << i << endl;
}

void print(double d) {
    cout << "Double: " << d << endl;
}

void print(const string& str) {
    cout << "String: " << str << endl;
}

void print(int i, double d) {
    cout << "Integer: " << i << ", Double: " << d << endl;
}

int main() {
    print(5);            // Calls print(int)
    print(3.14);        // Calls print(double)
    print("Hello!");    // Calls print(const string&)
    print(2, 3.14);     // Calls print(int, double)

    return 0;
}
