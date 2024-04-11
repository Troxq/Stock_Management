#include <iostream>
#include <string>
#include "container.h"

using namespace std;

int main(){
    container x("first");
    x.container_status();
    x.add_customer("cus1");
    x.add_customer("cus2");
    x.add_customer("cus3");
    x.add_customer("cus4");
    x.delete_customer("cus4");

    x.print_head_customer();
   
    x.customer_add_item("cus1", "apple");
    x.customer_add_item("cus1", "apple1");
    x.customer_add_item("cus1", "apple2");
    x.print_all_customer();
    
    x.customer_delete_item("cus1", "apple1");
    x.print_all_customer();
    x.customer_delete_item("cus1", "apple");
    x.customer_add_item("cus2", "apple");
    x.customer_add_item("cus2", "apple1");
    x.customer_add_item("cus3", "apple2");
    x.print_all_customer();


    
    /*
    x.add_NODE("first");
    x.add_NODE("second");
    x.print_head_NODE();
    x.delete_NODE("first");
    x.add_NODE("third");
    x.print_head_NODE();
    x.delete_NODE("third");
    x.delete_NODE("second");
    x.delete_NODE("first");
    x.add_NODE("last added");
    x.print_head_NODE();
    */
    

    return 0;
}