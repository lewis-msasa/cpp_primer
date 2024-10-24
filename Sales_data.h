#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

/*using namespace std;
this should not be included in header files
*/

// struct Sales_data {

//     Sales_data() = default;
//     Sales_data(const std::string &s) : book_no(s) {}
//     Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p*n) {}

//     std::string book_no;
//     unsigned units_sold = 0;
//     double revenue = 0.0;
//     std::string isbn() const { return book_no;}
//     Sales_data& combine(const Sales_data&);
//     double avg_price() const;
// };

class Sales_data {
    public:

        Sales_data() = default;
        Sales_data(const std::string &s) : book_no(s) {}
        Sales_data(const std::string &s, unsigned n, double p) : book_no(s), units_sold(n), revenue(p*n) {}
        //delegate constructors
        Sales_data() : Sales_data("",0,0){}
        Sales_data(std::string s) : Sales_data(s,0,0){}

        //suppressing explicit conversions
        //use explicit
        /*
          explicit Sales_data(const std::string &s) : book_no(s){}
        */

        //

        std::string isbn() const { return book_no;}
        Sales_data& combine(const Sales_data&);
        double avg_price() const;
    private: 
        std::string book_no;
        unsigned units_sold = 0;
        double revenue = 0.0;
   
};

#endif