#include <iostream>
#include <random>
#include <vector>
#include <cmath>

using namespace std;


vector<unsigned> good_randVec(){
    static default_random_engine e; //static to keep state so new numbers are generated at each call
    static uniform_int_distribution<unsigned> u {0,9};
    vector<unsigned> ret;
    for(size_t i=0;i<10;++i){
        ret.push_back(u(e));
    }
    return ret;
}
int main(){


    default_random_engine e;
    e.seed(42);
    for(size_t i=0; i < 10; ++i)
        cout << e() << " " << endl;

    //uniformly distributed from 0 to 9 inclusive
    uniform_int_distribution<unsigned> u(0,9);
    for(size_t i = 0; i < 10; ++i)
        cout << u(e) << endl;
    //real numbers
    //uniform_real_distribution<> fu(0,1); if we want the default return type
    uniform_real_distribution<double> fu(0,1);
    for (size_t i=0; i<10;++i)
        cout << fu(e) << " " <<endl;

    /*
     Generating numbers not uniformly distributed
    */
    normal_distribution<> n(4,1.5); //mean 4, std 1.5
    vector<unsigned> vals {9};
    for(size_t i=0; i< 10;++i){
        unsigned v = lround(n(e));
        if (v < vals.size())
            ++vals[v];
    }
    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;

    /*
     The Bernoulli Distribution
    */
    string resp;
    bernoulli_distribution b;
    //bernoulli_distribution b{.55}; // 55/45 chance
    do {
        bool first = b(e);
        cout << (first ? "I go first" : "you go first") << endl;
        cout << "play again? Enter 'yes' or 'no'" << endl;


    } while ( cin >> resp && resp[0] == 'y');

    return 0;

}