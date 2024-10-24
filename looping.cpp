#include <iostream>

using namespace std;

int main(){
    int sum = 0, val = 1;

    while (val <= 10){
        sum += val;
        ++val;
    }
    for (int val = 1; val <= 10; ++val){
        sum += val;
    }
    while (cin >> val)
      sum += val;
    cout << "The sum of 1 to 10 inclusive is " << sum << endl;

    return 0;
}