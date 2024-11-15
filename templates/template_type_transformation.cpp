// Type Transformation Library - Key Template Classes
#include <type_traits>
#include <iostream>

// 1. Basic Type Transformations
template<typename T>
void demonstrate_basic_transformations() {
    // Remove cv-qualifiers
    using CleanType = typename std::remove_cv<T>::type;
    
    // Add/remove const
    using ConstType = typename std::add_const<T>::type;
    using NonConstType = typename std::remove_const<T>::type;
    
    // Add/remove volatile
    using VolatileType = typename std::add_volatile<T>::type;
    using NonVolatileType = typename std::remove_volatile<T>::type;
    
    // Add/remove reference
    using LValueRef = typename std::add_lvalue_reference<T>::type;
    using RValueRef = typename std::add_rvalue_reference<T>::type;
    using NonRefType = typename std::remove_reference<T>::type;
}

// 2. Compound Type Transformations
template<typename T>
void demonstrate_compound_transformations() {
    // Pointer transformations
    using AddPtr = typename std::add_pointer<T>::type;
    using RemovePtr = typename std::remove_pointer<T>::type;
    
    // Array transformations
    using RemoveExtent = typename std::remove_extent<T>::type;  // Removes one dimension
    using RemoveAllExtents = typename std::remove_all_extents<T>::type;  // Removes all dimensions
}

// 3. Type Properties and Modifications
template<typename T>
void demonstrate_type_properties() {
    // Type properties
    constexpr bool is_const = std::is_const<T>::value;
    constexpr bool is_volatile = std::is_volatile<T>::value;
    constexpr bool is_array = std::is_array<T>::value;
    constexpr bool is_pointer = std::is_pointer<T>::value;
    constexpr bool is_reference = std::is_reference<T>::value;
    
    // Common type determination
    using CommonType = typename std::common_type<T, int>::type;
}

// 4. Example Usage
void example_usage() {
    // Basic type with cv-qualifiers
    typedef const volatile int cv_int;
    demonstrate_basic_transformations<cv_int>();
    
    // Array type
    typedef int array_type[10];
    demonstrate_compound_transformations<array_type>();
    
    // Pointer type
    typedef int* pointer_type;
    demonstrate_type_properties<pointer_type>();
    
    // Practical example: removing references and cv-qualifiers
    typedef const volatile int& complex_type;
    using cleaned_type = typename std::remove_cv<
        typename std::remove_reference<complex_type>::type
    >::type;  // Results in 'int'
}

// 5. Custom Type Transformation (Example)
template<typename T>
struct make_const_pointer {
    using type = const T*;
};

// 6. Type Identity (Useful for template metaprogramming)
template<typename T>
struct type_identity {
    using type = T;
};

int main() {
    example_usage();
    return 0;
}