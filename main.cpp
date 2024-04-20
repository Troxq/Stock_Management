#include <iostream>
#include "HQ.h"

int main()
{
    HQ * HQptr = new HQ("W",0);
    HQptr->add_container("first container");
    HQptr->add_container("second container");

    HQptr->HQ_add_customer("first container", "Woody"); 
    HQptr->HQ_add_customer("first container", "Kenji"); 

    HQptr->HQ_add_item("first container", "Woody", "apple");
    HQptr->HQ_add_item("first container", "Woody", "apple1");
    HQptr->HQ_add_item("first container", "Kenji", "banana");

    HQptr->HQ_delete_customer("first container", "Kenji");
    HQptr->print_all_container();
    delete(HQptr);
}