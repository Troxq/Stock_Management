#include <string> 
#include <iostream>
using namespace std;
class customer{
    // store customer name
    string customer_name;
    // give customer linklist

    customer* next_customer_ptr=NULL;

    public:
        customer(string="default_customer_name");
        void set_next_customer_ptr(customer*);
        string return_name();//for check, delete later
        customer * return_next_customer();
};

customer::customer(string inName){
    customer_name = inName;
}

void customer::set_next_customer_ptr(customer* next_customer_address){
    next_customer_ptr=next_customer_address;
}
string customer::return_name(){
    return customer_name;
}

customer * customer::return_next_customer(){
    return next_customer_ptr;
}
