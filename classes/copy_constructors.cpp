#include <iostream>



using namespace std;

/*

   If copy constructor not defined, the compile synthesizes one for us. Even when we define other constructors
   Same goes for copy assignment.
   Classes that need destructors need copy and assignment
*/

class Foo {
    public:
        Foo();
        Foo(const Foo&); //copy constructor
        //Foo(const Foo&) = delete; //to remove copy
        Foo  &operator=(const Foo&); // assignment operator
        Foo &operator=(const Foo&) = delete; //remove assignment
        ~Foo(); //destructor
};

int main(){




    return 0;
}