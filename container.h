#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <iostream>
#include "customer.h"
using namespace std;

extern string NextItemID;

class container{
    // with container branch name;
    string container_name;
    
    int customer_amount; //linked list property
    
    customer * customer_head_ptr=NULL; //linked list property

    container * next_container_ptr = NULL; //node property

    public:
        ~container();
        //linkedlist method
        container(string,int=0);
        void show_customer_amount(); // how many items;
        int add_customer(string);
        int delete_customer(string);
        void delete_all_customer();
        void print_head_customer();
        void print_all_customer();

        //node method
        void set_next_container_ptr(container*);
        string return_name();//for check, delete later
        container * return_next_container();
        bool is_customer_there(string);

        //access customer
        customer * return_customer_pointer(string);
        int container_transfer_in_container(string,string, string); //owner, receiver, item_id
        int customer_add_item(string, string ,string);
        int customer_transfer_item_in(string, string, string);
        int customer_delete_item(string,string);
};



bool container::is_customer_there(string customer_name){
    customer * t;
    t = customer_head_ptr;
    for(int i = 0; i < customer_amount; i++){
        if((t->return_name()).compare(customer_name)==0){
            return true;
        }
    }
    return false;
}

customer * container::return_customer_pointer(string inName){
    if((inName.compare("no_input")==0)){
        cout<<"no container name input"<<endl;
        return NULL;
    }
    customer * t;
    t = customer_head_ptr;
    for(int i = 0; i < customer_amount; i++){
        if((t->return_name()).compare(inName)==0){
            return t;
        }
        t=t->return_next_customer();
    }
    cout << "can't find customer named "<<inName<<endl;
    return NULL;
}

int container::container_transfer_in_container(string owner_name, string receiver_name, string item_id){
    customer * owner_ptr = return_customer_pointer(owner_name);
    customer * receiver_ptr = return_customer_pointer(receiver_name);
    item * t = owner_ptr->return_item_pointer(item_id);
    if(owner_ptr == NULL || receiver_ptr == NULL){
        return 0;
    }
    if((owner_ptr -> delete_item(item_id)) && (receiver_ptr -> transfer_item_in(item_id, t->return_name()))){
        return 1;
    }
    
    return 0;
}

container::~container(){
    cout<<"delete container "<< container_name<<endl;
    delete_all_customer();
}

void container::delete_all_customer(){
    customer * t;
    for(int i = 0; i < customer_amount;i++){
        t = customer_head_ptr;
        customer_head_ptr = customer_head_ptr->return_next_customer();
        delete t;
    }
    cout<<"deleted all "<<container_name<<"\'s customer"<<endl;  
    
}



void container::print_all_customer(){
    customer * t;
    t = customer_head_ptr;
    for(int i =0; i < customer_amount; i ++){
        cout<<t->return_name()<<"'s ";
        t->print_all_item();
        t = t->return_next_customer();
    }
}


int container::customer_delete_item(string inCustomername, string inItemid){
    //check valid id
    if((inItemid.compare("no_input")==0)){
        cout<<"no item id input"<<endl;
        return 0;
    }

    customer * t;
    t = customer_head_ptr;
    bool found=false;
    for (int i=0;i< customer_amount;i++)
    {
        if((t->return_name()).compare(inCustomername)!=0){
            t = t->return_next_customer();
        }else
        {
            //if found
            found = true;
            t->delete_item(inItemid);
            return 1;
        }
    }
    if(!found){
        cout<<"Sorry, can't find the name (" << inCustomername<<")"<<endl;
    }
    
    return 0;
}

int container::customer_add_item(string inCustomername,string NextItemID, string inItem_name){
    customer * t;
    t = customer_head_ptr;
    bool foundCustomer=false; //search for valid customer
    for (int i=0;i< customer_amount;i++){
        if((t->return_name()).compare(inCustomername)!=0){
            //if still not found move t ptr
            t = t->return_next_customer();
        }else if((t->return_name()).compare(inCustomername)==0){
            //if found
            foundCustomer = true;
            cout<<"Container \""<<container_name<<"\", ";
            t->add_item(NextItemID,inItem_name);
            return 1;
        }
    }
    if(!foundCustomer){
        cout<<"Sorry, can't find customer (" << inCustomername<<")"<<endl;
    }
    return 0;
    
}

int container::customer_transfer_item_in(string customername, string item_id, string item_name){
    customer * t;
    t = customer_head_ptr;
    bool foundCustomer=false; //search for valid customer
    for (int i=0;i< customer_amount;i++){
        if((t->return_name()).compare(customername)!=0){
            //if still not found move t ptr
            t = t->return_next_customer();
        }else if((t->return_name()).compare(customername)==0){
            //if found
            foundCustomer = true;
            cout<<"Container \""<<container_name<<"\", ";
            t->transfer_item_in(item_id,item_name);
            return 1;
        }
    }
    if(!foundCustomer){
        cout<<"Sorry, can't find customer (" << customername<<")"<<endl;
    }
    return 0;
}

container::container(string inName,int inAmount){
    container_name=inName; 
    customer_amount=inAmount;
}

void container::show_customer_amount(){
    cout<<customer_amount<<endl;
}

int container::add_customer(string customer_name){
    customer* new_customer_ptr;
    new_customer_ptr = new customer(customer_name);
    if (customer_head_ptr==NULL){
        customer_head_ptr = new_customer_ptr;
    }
    else
    {
        new_customer_ptr->set_next_customer_ptr(customer_head_ptr);
        customer_head_ptr=new_customer_ptr;
    }
    customer_amount++;
    cout<<"customer \""<<customer_name<<"\" added to Container \""<<container_name<<"\""<<endl;
    cout<<"Container "<< container_name<<"\'s current customer amount: "<<customer_amount<<endl;
    return 1;
}

void container::print_head_customer(){
    cout<<"this is print head"<<endl;
    cout<<"This is head of customer list : "<<customer_head_ptr->return_name()<<endl;
}

int container::delete_customer(string inName){
    customer * t, * prev;
    prev = NULL;
    t = customer_head_ptr;
    if(!t){
        //can't get customer ptr 
        cout<<"there's no customer in "<<container_name<<endl;
        return 0;
    }
    bool found=false;
    for (int i=0;i< customer_amount;i++){
        if((t->return_name()).compare(inName)!=0)
        {
            prev = t;
            t = t->return_next_customer();
        }
        else
        {
            //if found
            found = true;
            if(((t->return_next_customer()) == NULL)&&customer_amount>1) //if delete last customer
            {
                prev->set_next_customer_ptr(NULL);
            } 
            else
            {
                if ((prev == NULL) && (customer_amount >= 2)) //deleting head but more than one
                {
                    customer_head_ptr = customer_head_ptr->return_next_customer();
                }
                else if((prev==NULL)&&(customer_amount == 1))
                {
                    //last customer 
                    customer_head_ptr = NULL;
                }
                else 
                {
                    prev->set_next_customer_ptr(t->return_next_customer());
                }
            }
            delete(t);
            customer_amount--;
            cout<<"Container "<< container_name<<"\'s current customer amount: "<<customer_amount<<endl;
            return 1; // i don't know where i construct string from NULL to get that error
        }
    }
    
    if(!found){
        cout<<"Sorry, can't find the name (" << inName<<")"<<endl;
        cout<<"Container "<< container_name<<"\'s current customer amount: "<<customer_amount<<endl;
    }
    return 0;    
}



void container::set_next_container_ptr(container* next_container_address){
    next_container_ptr=next_container_address;
}

string container::return_name(){
    return container_name;
}

container * container::return_next_container(){
    return next_container_ptr;
}

#endif
