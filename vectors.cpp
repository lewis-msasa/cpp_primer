#include <iostream>
#include <vector>
#include <string>
#include "Sales_data.h";


using namespace std;

int main() {

    //vector<int> ivec;
    vector<Sales_data> sales_vect;
    vector<vector<string>> file;

    vector<string> v1 { "a", "an", "the"};
    vector<string> v2 {"a","an","the"};

    vector<int> ivec(10,-1);
    vector<string> svec(10,"hi!");

    vector<int> v3;
    for(int i= 0;i !=100; ++i)
        v3.push_back(i);

    for (auto i : v3)
        cout << i << " ";

    cout << endl;

    vector<unsigned> scores(11,0);
    unsigned grade;
    while (cin >> grade){
        if (grade == 0){
            break;
        }
        if(grade <= 100)
          ++scores[grade/10];
    }
    for (auto i : scores){
        cout << "----printing---" << endl;
        cout << i << endl;
    }

    return 0;
}

