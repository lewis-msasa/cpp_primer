#include <iostream>
#include <tuple>
#include <list>
using namespace std;


std::tuple<int, double, std::string> getValues() {
    int number = 42;
    double pi = 3.14159;
    std::string message = "Hello, world!";
    return std::make_tuple(number, pi, message);
}

int main(){

//std::tuple<std::string, std::vector<double>, int, std::list<int>> someVal = 
//std::make_tuple("string", vector<double>{3.14}, 42, std::list<int>{0, 1, 2, 3, 5});

std::tuple<int, double, std::string> myTuple(42, 3.14, "Hello");

//access member
cout << get<0>(myTuple) << endl;


typedef decltype(myTuple) t; //t is the type of myTuple
size_t sz = tuple_size<t>::value;  //size of the tuple
tuple_element<1, t>::type cnt = get<1>(myTuple); //type of specific element of tuple



return 0;
}