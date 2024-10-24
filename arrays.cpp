#include <iosteam>
#include <string>


using namespace std;

int main(){

     int arr[10]; //10 ints
     int *parr[42]; //array of 42 pointers

     string strs[10];

     unsigned scores [11] = {};
     unsigned grade;
     while(cin >> grade){
        if(grade <= 100)
           ++scores[grade/10];
     }

     int ia[10][20][30] = {0};


    return 0;
}