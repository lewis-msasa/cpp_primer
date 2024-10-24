#include <iostream>


using namespace std;
int fact(int val){
    return val;
}
void error_msg(initializer_list<string> il){
    for (auto beg = il.begin(); beg != il.end(); ++beg){
        cout << *beg << " ";
        cout << endl;
    }
}
void reset(int *ip){
   *ip = 0; //changes the value at the address
   ip = 0; //changes only the local of ip; argument is unchanged
}
void reset(int &i){
    i = 0; // changes the value of the object to which i refers
}
const string &shorterString(const string &s1, const string &s2){
    return s1.size() <= s2.size() ? s1 : s2;
}
char &get_val(string &str, string::size_type ix){
    return str[ix];
}
int main(){

    cout << fact(5)<< endl;
    int j = 42;
    reset(j);
    cout << j << endl;

    string s("Lewis Msasa");
    cout << s << endl;
    get_val(s, 0) = 'R';
    cout << s << endl;

    return 0;
}
//arrays cannot be passed by value - when passing, it is converted into a pointer to the first element
