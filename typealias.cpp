#include <iostream>

using namespace std;

int f() {
    return 10;
}
int main(){
    //using SI = Sales_item;
    typedef double wages; //wages is a synonym for double
    typedef wages base, *p; // base is a synonym for double, p for double*

    wages w = 100;

    //auto
    auto item = w * w; //type deduced by compiler

    //deduce from expression
    decltype (f()) sum = item; // type is whatever f() returns

    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; //has type const int
    decltype(cj) y = x; //has type const int& and is bound to x

    cout << sum << endl;
    return 0;
}


