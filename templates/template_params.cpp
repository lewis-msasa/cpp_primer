#include <iostream>

/*
Using class members that are types
- T::size_type * p; can either be type member access or static member access to the compiler
- to clarify, use typename
*/
template <typename T>
typename T::value_type top(const T& c){
    if(!c.empty())
        return c.back();
    else
        return typename T::value_type();
}

/*
DEFAULT TEMPLATE ARGUMENTS
*/

//class
template <typename T= int, int Size=10>
class Array{
    T data[Size];
    public:
        Array() = default;
        T& operator[](int index) {return data[index];}
        int getSize() const { return Size;}
};
Array<> arr1; //uses default
Array<double> arr2;

//function
template<typename T= int >
T getValue(T t = T()){
    return T{};
}
auto val1 = getValue<>(); //uses default
auto val2 = getValue<double>();

