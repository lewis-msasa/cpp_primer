#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>
#include <stack>

using namespace std;
int main(){

    /*
       - use vector unless there's a reason not to
       - list and forward_list have space overhead
       - for random access use vector or deque
       - for front back inserts use deque
    */
    // Fill constructor (5 elements, each initialized to 10)
    const std::vector<int> v2(5, 10);
    auto iter = v2.begin(), iter2 = v2.end();
    
    while(iter < iter2){

        cout << *iter << endl;
        iter++;

    }
    cout << "size : " << v2.size() << endl;
    cout << "capacity: " << v2.capacity() << endl;

    //string
    string s("C++ Primer"), s2 = s;

    s.insert(s.size(), " 4th Ed.");
    s2.append(" 4th Ed.");

    cout << s2 << endl;
    cout << s << endl;

    //CONTAINER ADAPTORS
    //stack<int> stk(deq) - copies elements from deq into stk
    //stack<string, vector<string>> str_stk;
    //stack<string, vector<string>> str_stk2(svec); - stack implemented on top of a vector

    /*
       Stack Adaptor
       - requires push_back, pop_back and back
       - it is built on a deque
    */
   stack<int> intStack;
   //fill it
   for(size_t ix = 0; ix != 10; ++ix){
      intStack.push(ix);
   }

   /*
     Queue Adaptor
        - requires pop, front, back, top, push, emplace
   */


    return 0; 
}