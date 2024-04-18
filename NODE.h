#include <string> 
#include <iostream>
using namespace std;
class NODE{
    // store NODE name
    string NODE_name;
    // give NODE linklist

    int amount = 0; // GOT : add amount for use in orderFormat.h

    NODE* next_NODE_ptr=NULL;

    public:
        NODE(string="default_NODE_name", int = 0);
        void set_next_NODE_ptr(NODE*);
        string return_name();//for check, delete later
        NODE * return_next_NODE();

        int return_amount(); // GOT : for display in sendorder

};

NODE::NODE(string inName, int a){ // GOT : add amount for use in orderFormat.h
    NODE_name = inName; 
    amount = a; //GOT : add amount for use in orderFormat.h
    
}

void NODE::set_next_NODE_ptr(NODE* next_NODE_address){
    next_NODE_ptr=next_NODE_address;
}
string NODE::return_name(){
    return NODE_name;
}

NODE * NODE::return_next_NODE(){
    return next_NODE_ptr;
}

int NODE::return_amount()
{
    return amount;
}