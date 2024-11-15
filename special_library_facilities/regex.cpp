#include <iostream>
#include<regex>


using namespace std;

int main(){

   string pattern{"[^c]ei"}; //find ei that follow a character other than c
   pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
   regex r{pattern};
   smatch results; //object to hold results
   string test_str = "receipt freind theif receive";
   if(regex_search(test_str, results, r))
        cout << results.str() << endl;

   string phone = "(\\()?(\\d{3})(\\))?([-.  ])?(\\d{3}) ([-.  ])?(\\d{4})";
   regex re{phone};
   smatch m;
   string s;
   string fmt = "$2.$5.$7";
   while (getline(cin,s))
     cout << regex_replace(s, re, fmt) << endl;



   return 0;
}