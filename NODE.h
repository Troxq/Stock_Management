#include <string> 
#include <iostream>
using namespace std;
class NODE{
    // store NODE name
    string NODE_name;
    // give NODE linklist

    NODE* next_NODE_ptr=NULL;

    public:
        NODE(string="default_NODE_name");
        void set_next_NODE_ptr(NODE*);
        string return_name();//for check, delete later
        NODE * return_next_NODE();
};

NODE::NODE(string inName){
    NODE_name = inName;
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
