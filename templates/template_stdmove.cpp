#include <iostream>
#include <type_traits>

//how move is done in std

template <typename T>
typename std::remove_reference<T>::type&& move(T&& t){

 return static_cast<typename remove_reference<T>::type&&>(t);
}