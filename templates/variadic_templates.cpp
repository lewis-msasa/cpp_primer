#include <iostream>
#include <utility>

template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n'; // Fold expression (since C++17)
    cout << sizeof...(args) << std::endl;
}
// Recursive case
template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << ' ';
    print(rest...); // Recursive call with the remaining arguments
}
// Generic forwarding function
template <typename Func, typename... Args>
void call(Func&& func, Args&&... args) {
    // Forwarding parameter pack 'args' to 'func' using std::forward
    std::forward<Func>(func)(std::forward<Args>(args)...);
}

int main() {
    print(1, 2.5, "Hello", 'c'); // Output: 1 2.5 Hello c
    print(1, 2.5, "Hello", 'c'); // Output: 1 2.5 Hello c
}