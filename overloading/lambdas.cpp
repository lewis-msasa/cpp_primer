#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use a lambda to print each element
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });

    std::cout << std::endl;

    // Use a lambda to find an element
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 3; // Find the first number greater than 3
    });

    if (it != numbers.end()) {
        std::cout << "First number greater than 3: " << *it << std::endl;
    }

    return 0;
}
