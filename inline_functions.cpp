#include <iostream>
using namespace std;

//optimizes small and frequently called functions
inline int square(int x) {
    return x * x;
}

//constexpr function can be used in a constant expression
constexpr int new_size() { return 42; }

int main() {
    int number = 5;
     
    constexpr int foo = new_size();
    
    cout << "Square of " << number << " is " << square(number) << endl;

    return 0;
}
