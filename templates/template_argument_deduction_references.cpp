#include <iostream>>
/*
From Lvalue reference function params
 - if ordinary lvalue, then we can only pass an lvalue
*/
template <typename T> void f1(T&);
template <typename T> void f2(const T&);

/*
from Rvalue reference function params
*/
template <typename T> void f3(T&&);


int main(){


int i = 0;
const int ci = 0;
f1(i);
// f1(2); - its an rvalue
f2(ci);
f2(i);
f2(2); // const& param can be bound to an rvalue

f3(42);
f3(i); // lvalue; T is int&
f3(ci); //lvalue; T is const int&


return 0;
}
