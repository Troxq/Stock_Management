#include <iostream>
#include "HQ.h"

//initial function
// void loadData(HQ *&);

// void loadData(HQ *&HQptr){
    
// }

int main()
{
    //load file()


    HQ * HQptr = new HQ("W",0);
    HQptr->add_container("first_container");
    HQptr->add_container("second_container");
    HQptr->add_container("third_container");

    HQptr->HQ_add_customer("second_container", "Kenji"); 
    HQptr->HQ_add_customer("first_container", "Kenji");
    HQptr->HQ_add_customer("first_container", "Woody");
    HQptr->HQ_add_customer("third_container", "Woody");
    HQptr->HQ_delete_customer("third_container", "Woody");



    HQptr->HQ_add_item("first_container", "Kenji", "apple");
    HQptr->HQ_add_item("first_container", "Woody", "book");
    HQptr->HQ_add_item("third_container", "Woody", "hamburger");
    HQptr->HQ_add_item("third_container", "Woody", "computer");
    HQptr->HQ_add_item("second_container", "Kenji", "banana");

    HQptr->HQ_transfer_in_container("first_container", "Woody", "Kenji", "book");
    HQptr->HQ_transfer_over_container("Kenji", "first_container", "second_container", "apple");
    
    HQptr->print_all_container();
    
    //delete old save file and create new / overwrite
    // -- here --
    //

    delete(HQptr);
}