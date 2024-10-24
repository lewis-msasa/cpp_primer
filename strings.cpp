#include <string>
#include<iostream>
using std::string;
using namespace std;

int main(){

    string s1; //defaults to empty string
    string s2 = s1; //equic to s2(s1) - a copy of s1
    string s3 = "Hi";

    string s4(10,'c'); //does 10 'c'

    string word;
    /*while (cin >> word){
          if (word == "c")
              break;
          cout << word << endl;
    }*/
    string line;
    while (getline(cin,line)){
        if (line == "c")
           break;
        if (!line.empty())
            cout << line << endl;
    }

    string str("this is the time I have been waiting for");

    for( auto c : str){
        //print every character in str
        cout << c << endl;
    }
          
    string s("Hello world!!!!!");

    decltype(s.size()) punct_cnt = 0;

    for (auto c : s){
        if(ispunct(c))
          ++punct_cnt;
        else 
           c = toupper(c); // c is a reference so it changes s
    }  
    

    return 0;
}