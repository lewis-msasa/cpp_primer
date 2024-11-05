#include <iostream>

/*
each instantiation of the template class has its own instance of static members.
*/

template <typename T>
class Counter{
    public:
      Counter(){
        ++count;
      }
      static int getCount(){
        return count;
      }
    private:
        static int count;
};
template<typename T>
int Counter<T>::count =0;