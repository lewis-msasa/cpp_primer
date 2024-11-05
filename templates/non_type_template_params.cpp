#include <iostream>

/*
 nontype params represents a value rather than a type
*/

template <typename T, int Size> // size is a non-type template parameter
class FixedArray {
    T arr[Size]; //fixed size specified by the template parameter
    public:
        void set(int index, T value){
            if (index >= 0 && index < Size){
                arr[index] = value;
            }
        }
        T get(int index) const {
            return (index >= 0 && index < Size) ? arr[index] : T();

        }
        int getSize() const {
            return Size; //direct access because its a compile-time constant
        }
};

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M]){
    std::cout << N << std::endl;
    std::cout << M << std::endl;
    return strcmp(p1,p2);

}

int main() {
    FixedArray<int, 5> array;
    array.set(0,10);
    array.set(1,20);

    std::cout << "Array size: " << array.getSize() << std::endl;
    std::cout << "First element: " << array.get(0) << std::endl;
    std::cout << compare("hi", "Lewis") << std::endl;
    return 0;
}
