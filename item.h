#include <string> 
#include <iostream>

#ifndef ITEM_H
#define ITEM_H
using namespace std;
class item{
    // store item id
    string item_name;
    string item_id;
    item* next_item_ptr=NULL;

    public:
        ~item();
        item(string="no_item_id", string="no_item_name");
        void set_next_item_ptr(item*);
        string return_id(); 
        void show_id();
        void show_name();
        item * return_next_item();
};

item::~item(){
    show_id();cout<<" ";show_name();cout<<"deleted"<<endl;
}

void item::show_id(){
    cout<<item_id;
}
void item::show_name(){
    cout<<item_name;
}

item::item(string inId, string inName){
    item_id = inId;
    item_name = inName;
}

void item::set_next_item_ptr(item* next_item_address){
    next_item_ptr=next_item_address;
}
string item::return_id(){
    return item_id;
}

item * item::return_next_item(){
    return next_item_ptr;
}
#endif