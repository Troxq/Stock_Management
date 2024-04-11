#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <iostream>
#include "customer.h"
using namespace std;

class container{
    // with container branch name;
    string container_name;
    
    int customer_amount; //linked list property
    
    customer * customer_head_ptr=NULL; //linked list property

    container * next_container_ptr = NULL; //node property

    public:
        //linkedlist method
        container(string="default_container",int=0);
        void container_status(); // how many items;
        int add_customer(string="no_name");
        void delete_customer(string);
        void print_head_customer();
        void print_all_customer();

        //node method
        void set_next_container_ptr(container*);
        string return_name();//for check, delete later
        container * return_next_container();

        //access customer
        int customer_add_item(string="no_name" ,string="no_id");
        int customer_delete_item(string="no_name",string="no_id");
};
void container::print_all_customer(){
    customer * t;
    t = customer_head_ptr;
    cout<<"--------------------------------------------------"<<endl;
    for(int i =0; i < customer_amount; i ++){
        cout<<t->return_name()<<"'s ";
        t->print_all_item();
        t = t->return_next_customer();
    }
    cout<<"--------------------------------------------------"<<endl;
    
}


int container::customer_delete_item(string inCustomername, string inItemid){
    //check valid id
    if((inItemid.compare("no_id")==0)){
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

int container::customer_add_item(string inCustomername, string inItemid){
    //check valid id
    if((inItemid.compare("no_id")==0)){
        cout<<"no item id input"<<endl;
        return 0;
    }

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
            t->add_item(inItemid); 
            return 1;
            }
    }
    if(!foundCustomer){
        cout<<"Sorry, can't find customer (" << inCustomername<<")"<<endl;
    }
    return 0;
    
}

container::container(string inName,int inAmount){
    container_name=inName; 
    customer_amount=inAmount;
}

void container::container_status(){
    cout<<"container name: "<< container_name<<endl;
}

int container::add_customer(string customer_name){
    //check valid name
    if((customer_name.compare("no_name")==0)){
        cout<<"no item id input"<<endl;
        return 0;
    }

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

void container::delete_customer(string inName){
    customer * t, * prev;
    prev = NULL;
    t = customer_head_ptr;
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
                    cout<<"deleting head";
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
            cout<<"\""<<inName<<"\" deleted"<<endl;
            customer_amount--;
            cout<<"Container "<< container_name<<"\'s current customer amount: "<<customer_amount<<endl;
            break; // i don't know where i construct string from NULL to get that error
        }
    }
    
    if(!found){
        cout<<"Sorry, can't find the name (" << inName<<")"<<endl;
        cout<<"Container "<< container_name<<"\'s current customer amount: "<<customer_amount<<endl;
    }
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
