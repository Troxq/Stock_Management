#include <string> 
#include <iostream>

#ifndef ITEM_H
#define ITEM_H
using namespace std;
class item{
    // store item id
    string item_id;

    item* next_item_ptr=NULL;

    public:
        item(string="default_item_name");
        void set_next_item_ptr(item*);
        string return_id(); 
        void show_id();
        item * return_next_item();
};

void item::show_id(){
    cout<<item_id;
}

item::item(string inId){
    item_id = inId;
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