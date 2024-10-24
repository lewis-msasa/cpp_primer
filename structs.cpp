#include <iostream>
#include "Sales_data.h"


using namespace std;

double Sales_data::avg_price() const {
    if(units_sold){
      return revenue/units_sold;
    }
    else{
      return 0;
    }
}
Sales_data& Sales_data::combine(const Sales_data &rhs){

   units_sold += rhs.units_sold;
   revenue += rhs.revenue;
   return *this;

}

int main(){
   
     Sales_data sales;
     sales.book_no = "1234";
     sales.units_sold = 5;
     sales.revenue = 100.00;

     Sales_data sales2;
     sales2.book_no = "12345";
     sales2.units_sold = 50;
     sales2.revenue = 1500.00;


     cout << sales.revenue << endl;
     cout << sales.avg_price() << endl;
     cout << sales.combine(sales2).avg_price() << endl;

    return 0;
}