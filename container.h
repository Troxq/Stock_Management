#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <iostream>
#include "customer.h"
using namespace std;

class container{
    // with container branch name;
    string container_name;
    customer * customer_head_ptr=NULL;
    int customer_amount;

    // add customer name then store
    // add container later
    public:
        container(string="default_container",int=0);
        void container_status(); // how many items;
        void add_customer(string);
        void delete_customer(string);
        void print_head_customer();
    /*
    .add(id);
    .searchid(id) //loop every customer
    */    
};

container::container(string inName,int inAmount){
    container_name=inName; 
    customer_amount=inAmount;
}

void container::container_status(){
    cout<<"container name: "<< container_name<<endl;
}

void container::add_customer(string customer_name){
    customer* new_customer_ptr;
    new_customer_ptr = new customer(customer_name);
    if (customer_head_ptr==NULL){
        customer_head_ptr = new_customer_ptr;
    }else{
        new_customer_ptr->set_next_customer_ptr(customer_head_ptr);
        customer_head_ptr=new_customer_ptr;
    }
    customer_amount++;
    cout<<"customer \""<<customer_name<<"\" added"<<endl;
    cout<<"Current customer amount : "<<customer_amount<<endl;
    
};

void container::print_head_customer(){
    cout<<"This is head of customer list : "<<customer_head_ptr->return_name()<<endl;
}

void container::delete_customer(string inName){
    customer * t, * prev;
    prev = NULL;
    t = customer_head_ptr;
    bool found=false;
    for (int i=0;i< customer_amount;i++){
        if((t->return_name()).compare(inName)!=0){
            prev = t;
            t = customer_head_ptr->return_next_customer();
        }else{
            //if found
            found = true;
            if(( t->return_next_customer() == NULL)&&customer_amount>1) //if delete last node
            {
                prev->set_next_customer_ptr(NULL);
                delete (t);
            } 
            else
            {
                if (prev == NULL && customer_amount >= 2) //deleting head but more than one
                {
                    customer_head_ptr = customer_head_ptr->return_next_customer();
                    delete t;
                }
                else if(customer_amount == 1)
                {
                    //last customer 
                    customer_head_ptr = NULL;
                    delete (t);
                }
                else if((prev!= NULL) && (customer_amount>=2))
                {
                    cout<<"else case"<<endl;
                    customer_head_ptr = NULL;
                    prev->set_next_customer_ptr(t->return_next_customer());
                    customer_amount--;
                    delete(t);
                }
            }
            cout<<"\""<<inName<<"\" deleted"<<endl;
            customer_amount--;
            cout<<"remaining customer amount: "<<customer_amount<<endl;
        }
    }
    if(!found){
        cout<<"Sorry, can't find the name (" << inName<<")"<<endl;
    }
}


#endif
