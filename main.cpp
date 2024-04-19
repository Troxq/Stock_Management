#include <iostream>
#include "HQ.h"

int main()
{
    HQ * HQptr = new HQ("W",0);
    HQptr->add_container("first container");
    HQptr->add_container("second container");
    HQptr->print_all_container();
    
}