#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <vector>

//steam is passed and returned through references and cannot be const
/*
 IO State
  - badbit - system level failure
  - failbit - recoverable error
  - eofbit - end of file
  - goodbit - no failures

  * rdstate - returns iostate corresponding to the current state of the iosteam
  * setstate - 
  * clear - 
*/
using namespace std;

struct PersonInfo{
    string name;
    vector<string> phones;
};

int main() {
 
    auto old_state = cin.rdstate();
    cin.clear();

    std::string word;
    while(cin >> word){
        if(word == "y"){
            break;
        }
        else{
            cout << cin.rdstate() << endl;
        }
    }
    cout << old_state << endl;
    //cin.setstate(cin.failbit);
    cout << cin.rdstate() << endl;
    cin.setstate(old_state);

    //flushing
    cout << "this string" << endl;
    cout << "Another with a flush" << flush;
    cout << "With an ending" << ends;

    //to flush after every subsequent right
    cout << unitbuf;
    //flash everything immediately
    cout << nounitbuf; // normal buffering

    //typing input and output streams together
    //cin.tie(&cout);


    //FILES
    ifstream in("file.txt");
    std::string line;
    while (std::getline(in, line)) {  // Read each line from the file
        std::cout << line << std::endl;  // Print the line to the console
    }
    in.close();
    ofstream out("file.txt", ofstream::app);
    out << "Another line" << endl;  
    out.close();

    //STRINGS
    /*
       - istringstream
       - ostringstream
    */
    string l, w;
    vector<PersonInfo> people;
    while(std::getline(cin,l)){
        if(l == "Y"){
            break;
        }
        PersonInfo info;
        istringstream record(l);
        cout << l << endl;
        record >> info.name;
        cout << info.name << endl;
        while(record >> w){
            cout <<"Phone " << w << endl;
            info.phones.push_back(w);
        }
        people.push_back(info);

       
    }
    cout <<"Get the people" << endl;
    for(auto p: people){
         cout <<"-----------" << endl;
         cout << p.name << endl;
         cout <<"---Phones---" << endl;
         for(auto phone: p.phones){
            
            cout << phone << endl;

         }
    }

    return 0;
}