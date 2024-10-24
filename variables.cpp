#include <iostream>

using namespace std;


extern const int bufferSize = 0;
int main(){
    const int bufSize = 512;
    const int &r1 = bufSize; // both ref and underlying object are const

    int errNumb = 0;
    int *const curErr = &errNumb; // currErr will always point to errNumb
    const double pi = 3.14159;
    const double *const pop = &pi; //const pointer to a const object

    /*
    constexpr - implicitly const and initialized by constant expressions - evaluated at compuile time
    we can only assign literal types to these
    */
   constexpr int mf = 20; // 20 is a constant expression
   constexpr int limit = mf + 1;

   const int *p = nullptr; //p is a pointer to a const int
   constexpr int *q = nullptr; //q is a const pointer to int
   

}