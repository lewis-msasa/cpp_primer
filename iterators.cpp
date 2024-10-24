#include <iostream>
#include <string>
using namespace std;


int main (){
    string s("Lewis Msasa is so intelligent");

    if(s.begin() != s.end()){
        auto it = s.begin();
        //deferencing an iterator gets the object the iterator denotes
        *it = toupper(*it);
        cout << *it << endl;
    }
    for(auto it = s.cbegin();
    it != s.cend() && *it != '\0'; ++it)
       cout << *it << endl;


    auto beg = s.begin();
    auto end = s.end();
    auto mid = s.begin() + (end - beg)/2;
    string sought = "so";
    while(mid != end && *mid != sought){
        if (sought < *mid){
             end = mid;
        }
        else{
            beg = mid + 1;
        }
        mid = beg + (end - beg)/2;
       
    }


    return 0;
}