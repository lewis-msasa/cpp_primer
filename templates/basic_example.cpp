#include <iostream>

template <typename T>

T add(T a, T b){
    return a + b;
}
template <typename T> int compare(const T &v1, const T &v2){
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
template <typename T> T get(T* p){
    T tmp = *p;
    return tmp;
}
template <typename T, class U> T calc(const T& a, const U& b){

    return a;
}
int main() {
    std::cout << add(5,3) << std::endl;
    std::cout << add(5.5, 3.3) << std::endl;

    return 0;
}