/*
The compiler generates a new instantiation rather than converting the arguments

*/

/*
Function parameter that use the same template parameter type
*/

/*
Specifying an explic Template Argument
*/
template <typename T1, typename T2, typename T3>
T1 sum(T2,T3);

int i = 0;
long lng = 10.00;
// T1 is provided while T2,T3 are deduced
auto val3 = sum<long long>(i,lng);

/*
Trailing return types and type transformation
*/
template <typename It>
auto &fcn(It beg, It end){
    return *beg;
}
//type transformation
