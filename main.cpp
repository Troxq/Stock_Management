#include <iostream>
#include "HQ.h"

int main()
{
    HQ * HQptr = new HQ("W",0);
    HQptr->add_container("first container");
    HQptr->add_container("second container");

    HQptr->HQ_add_customer("second container", "Kenji"); 
    HQptr->HQ_add_customer("first container", "Kenji"); 

    HQptr->HQ_add_item("first container", "Kenji", "apple");
    HQptr->HQ_add_item("second container", "Kenji", "banana");

    HQptr->transfer_over_container("Kenji", "first container", "second_container", "apple");
    HQptr->print_all_container();
    delete(HQptr);
}