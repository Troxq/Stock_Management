#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "item.h"
using namespace std;

extern string NextItemID;

class customer{
    // with customer branch name;
    string customer_name;
    
    //linked list property
    int item_amount=0; 
    item * item_head_ptr=NULL; 

    //node property
    customer * next_customer_ptr = NULL; 

    public:
        ~customer();
        //container method
        customer(string="default_customer",int=0);
        void show_item_amount();
        int add_item(string,string);
        int transfer_item_in(string, string);
        int delete_item(string);
        void print_head_item();
        void print_all_item();
        void delete_all_item();
        item * return_item_pointer(string="no_input");

        //node method
        void set_next_customer_ptr(customer*);
        string return_name();//for check, delete later
        customer * return_next_customer();
        void incrementID();
};

void customer::incrementID() {
    int number;
    std::istringstream(NextItemID) >> number;

    // Increment the number
    number++;

    // Convert the incremented number back to string
    std::ostringstream oss;
    oss << std::setw(NextItemID.length()) << std::setfill('0') << number;
    NextItemID = oss.str();
}

customer::~customer(){
    cout<<"delete customer "<< customer_name<<endl;
    delete_all_item();
}

void customer::delete_all_item(){
    item * t;
    for(int i = 0; i < item_amount;i++){
        t = item_head_ptr;
        item_head_ptr = item_head_ptr->return_next_item();
        delete t;
    }
    cout<<"deleted all "<<customer_name<<"'s items "<<endl;
}

void customer::print_all_item(){
    item * t;
    t = item_head_ptr;
    cout<<"Item: ";
    for(int i =0; i < item_amount; i++){
        t->show_id();cout<<"_";t->show_name(); // 00032_banana
        if(i!=(item_amount-1)){
            cout<<" -> ";
            t = t->return_next_item();
        }
    }
    cout<<endl;
}

customer::customer(string inName,int inAmount){
    customer_name=inName; 
    item_amount=inAmount;
}

void customer::show_item_amount(){
    cout<<"("<<item_amount<<")";
}

int customer::add_item(string NextItemID,string item_name){
    item* new_item_ptr;
    new_item_ptr = new item(NextItemID, item_name);
    if (item_head_ptr==NULL){
        item_head_ptr = new_item_ptr;
    }
    else
    {
        new_item_ptr->set_next_item_ptr(item_head_ptr);
        item_head_ptr=new_item_ptr;
    }
    item_amount++;
    cout<<"Customer "<<"\""<<customer_name<<"\""<<" added item \""<<NextItemID<<"_"<<item_name<<"\""<<endl;
    cout<<"Customer "<< customer_name<<"\'s current items amount: "<<item_amount<<endl;
    incrementID();
    return 1;
};

item * customer::return_item_pointer(string item_id){
    if((item_id.compare("no_input")==0)){
        cout<<"no container name input"<<endl;
        return NULL;
    }
    item * t;
    t = item_head_ptr;
    for(int i = 0; i < item_amount; i++){
        if((t->return_id()).compare(item_id)==0){
            return t;
        }
        t=t->return_next_item();
    }
    cout<<"can't find item id "<<item_id<<endl;
    return nullptr;
}

int customer::transfer_item_in(string item_id, string item_name){
    item* new_item_ptr;
    new_item_ptr = new item(item_id, item_name);
    if (item_head_ptr==NULL){
        item_head_ptr = new_item_ptr;
    }
    else
    {
        new_item_ptr->set_next_item_ptr(item_head_ptr);
        item_head_ptr=new_item_ptr;
    }
    item_amount++;
    cout<<"Customer "<<"\""<<customer_name<<"\""<<" transfer item \""<<item_id<<"_"<<item_name<<" in\""<<endl;
    cout<<"Customer "<< customer_name<<"\'s current items amount: "<<item_amount<<endl;
    return 1;
}

void customer::print_head_item(){
    cout<<"This is head of item list : "<<item_head_ptr->return_id()<<endl;
}

int customer::delete_item(string item_id){
    item * t, * prev;
    prev = NULL;
    t = item_head_ptr;
    bool found=false;
    for (int i=0;i< item_amount;i++){
        if((t->return_id()).compare(item_id)!=0){
            prev = t;
            t = t->return_next_item();
        }else{
            //if found
            found = true;
            if(((t->return_next_item()) == NULL)&&item_amount>1) //if delete last item
            {
                prev->set_next_item_ptr(NULL);
            } 
            else
            {
                if (prev == NULL && item_amount >= 2) //deleting head but more than one
                {
                    item_head_ptr = item_head_ptr->return_next_item();
                }
                else if((prev==NULL)&&(item_amount == 1))
                {
                    //last item 
                    item_head_ptr = NULL;
                }
                else if((prev!= NULL) && (item_amount>=2))
                {
                    prev->set_next_item_ptr(t->return_next_item());
                }
            }
            delete(t);
            cout<<"\""<<item_id<<"\" deleted"<<endl;
            item_amount--;
            return 1;
        }
    }
    if(!found){
        cout<<"Sorry, can't find item id : " << item_id<<endl;
        cout<<"\""<<customer_name<<"\" "<< "item amount: "<<item_amount<<endl;
    }
    return 0;
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

#endif
