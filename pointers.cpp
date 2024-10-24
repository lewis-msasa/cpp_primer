#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    /*pointer holds address of another object*/
    int *ip1, *ip2;
    double dp, *dp2;

    int ival = 42;
    /*p hold address of ival; p is a pointer to ival*/
    int *p = &ival;

    cout << *p << endl;

    int *p1 = nullptr; //equivalent to int *p1 = 0;
    int *p2 = 0; //init to literal constant 0

    int *p3 = p;

    cout << *p3 << endl;

    //void* pointers can hold address to any object
    //
    void *pv = &ival;

    cout << pv << endl;

    //ival = 1024;
    int *pi = &ival; //point to an int
    int **ppi = &pi; //point to a pointer to an int

    return 0;
}