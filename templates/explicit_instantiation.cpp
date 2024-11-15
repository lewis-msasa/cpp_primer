#include<iostream>

/*
same instantiation mught appear in multiple object files. Explicit instantiation prevents that
forces the compiler to generate code for a specific template instantiation in a particular translation unit.
*/

//Basic
template<typename T>
class MyClass {
    public:
        T getValue() const { return value;}
    private:
        T value;
};
//explicit instantiation in source file
template class MyClass<int>;
template class MyClass<double>;


//member function explicit instantiation
//header file
template<typename T>
class Container{
    public:
        void add(const T& item);
        T get() const;
        void remove();
    private:
        std::vector<T> data;
};
//source
//explicit instantiation of a class
template class Container<int>;
//of member functions
template void Container<double>::add(const double&);
template double Container<double>::get() const;

//function template explicit instantiation

//header file
template<typename T>
T maximum(T a, T b){
    return (a > b) ? a : b;
}

//source file
template int maximum<int>(int, int);
template double maximum<double>(double, double);



/*
USING EXTERN
- using extern templates to prevent instantiation
*/

//header file
template<typename T>
class Complex{
    public:
        Complex(T real, T imag);
        T magnitude() const;
    private:
        T re, im;
};

//in one source file
template class Complex<double>;

//in other source files
extern template class Complex<double>;


