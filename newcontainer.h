#ifndef NEWCONTAINER_H
#define NEWCONTAINER_H
#include <string>
#include <iostream>
#include "customer.h"
using namespace std;

class containerv2{
    // with containerv2 branch name;
    string containerv2_name;
    
    int customer_amount; //linked list property
    
    customer * customer_head_ptr=NULL; //linked list property

    containerv2 * next_containerv2_ptr = NULL; //node property

    public:
        //container method
        containerv2(string="default_containerv2",int=0);
        void containerv2_status(); // how many items;
        void add_customer(string);
        void delete_customer(string);
        void print_head_customer();

        //containerv2 method
        containerv2(string="default_containerv2_name");
        void set_next_containerv2_ptr(containerv2*);
        string return_name();//for check, delete later
        containerv2 * return_next_containerv2();
    /*
    .add(id);
    .searchid(id) //loop every customer
    */    
};

containerv2::containerv2(string inName,int inAmount){
    containerv2_name=inName; 
    customer_amount=inAmount;
}

void containerv2::containerv2_status(){
    cout<<"containerv2 name: "<< containerv2_name<<endl;
}

void containerv2::add_customer(string customer_name){
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

void containerv2::print_head_customer(){
    cout<<"This is head of customer list : "<<customer_head_ptr->return_name()<<endl;
}

void containerv2::delete_customer(string inName){
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
            if(( t->return_next_customer() == NULL)&&customer_amount>1) //if delete last containerv2
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

containerv2::containerv2(string inName){
    containerv2_name = inName;
}

void containerv2::set_next_containerv2_ptr(containerv2* next_containerv2_address){
    next_containerv2_ptr=next_containerv2_address;
}
string containerv2::return_name(){
    return containerv2_name;
}

containerv2 * containerv2::return_next_containerv2(){
    return next_containerv2_ptr;
}

#endif
