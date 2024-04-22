#include <iostream>
#include "container.h"
#include <string>
#include <vector>

#ifndef HQ_H
#define HQ_H

using namespace std;

class HQ{
    string HQ_name;
    int container_amount; //linked list property
    container * container_head_ptr=NULL; //linked list property

    public:
        HQ(string inName="no_name",int inAmount=0){
            HQ_name = inName;
            container_amount = inAmount;
        };
        ~HQ();

        //for HQ
        vector<vector<string>> read_and_return_container_vector(container*);
        int add_container(string="no_name", int=0);
        void delete_container(string);
        void print_head_container();
        void print_all_container();
        container * return_container_pointer(string="no_name");
        int show_customer_in_container(string="no_name");
        void delete_all_container();

        //for Manager & Staff
        int HQ_transfer_in_container(string="no_name",string="no_name", string="no_name", string="no_id"); //owner, item, receiver
        int HQ_transfer_over_container(string="no_name", string="no_name", string="no_name", string="no_id");//customer, origin container, destination container, item
        int HQ_add_customer(string="no_name",string="no_name"); //need container and actual customer name 
        int HQ_delete_customer(string="no_name", string="no_name"); //need container and actual customer name 
        int HQ_add_item(string="no_name", string="no_name", string="no_id"); //need container, customer name, item id 
};

vector<vector<string>> read_and_return_container_vector(container*)


int HQ::HQ_transfer_in_container(string container_name,string owner_name, string receiver_name, string item_id){
    container * container_ptr = return_container_pointer(container_name);

    if(container_ptr){
        if(container_ptr->container_transfer_in_container(owner_name, receiver_name, item_id)){
            return 1;
        }
    }
    cout<<"can't transfer"<<endl;
    return 0;
}

int HQ::HQ_transfer_over_container(string customer_name, string origin_container_name, string des_container_name, string item_id){
    container * origin_ptr = return_container_pointer(origin_container_name);
    container * des_ptr = return_container_pointer(des_container_name);
    if(origin_ptr == NULL || des_ptr == NULL){
        return 0;
    }
    if((origin_ptr->is_customer_there(customer_name))&&(des_ptr->is_customer_there(customer_name)) ){
        if(origin_ptr->customer_delete_item(customer_name,item_id)){
            des_ptr->customer_add_item(customer_name,item_id);
            cout<<"transfer "<<item_id<<" complete"<<endl;
            return 1;
        }
    }
    return 0;
}

void HQ::delete_all_container(){
    container * t;
    for(int i = 0; i < container_amount;i++){
        t = container_head_ptr;
        container_head_ptr = container_head_ptr->return_next_container();
        delete t;
    }
    cout<<"deleted all "<<HQ_name<<"\'s container"<<endl;  

}

HQ::~HQ(){
    cout<<"delete HQ "<< HQ_name<<endl;
    delete_all_container();
}

int HQ::HQ_delete_customer(string container_name, string customer_name){
    container * t = return_container_pointer(container_name);
    if(t == NULL){
        cout<<"no container name";
        return 0;
    }
    
    t->delete_customer(customer_name);
    return 1;
}

int HQ::HQ_add_item(string container_name, string customer_name, string item_id){
    container * t = return_container_pointer(container_name);

    if(t == NULL){
        cout<<"no container name";
        return 0;
    }
    t->customer_add_item(customer_name, item_id);
    return 1;
}

int HQ::show_customer_in_container(string container_name){
    container * t = return_container_pointer(container_name);
    if(t == NULL){
        cout<<"no container name";
        return 0;
    }
    t->print_all_customer();
    return 1;
}

int HQ::HQ_add_customer(string container_name, string customer_name){
    container * t = return_container_pointer(container_name);
    if(t==NULL){
        cout<<"no container name";
        return 0;
    }
    t->add_customer(customer_name);
    return 1;
}

container * HQ::return_container_pointer(string inName){
    if((inName.compare("no_name")==0)){
        cout<<"no container name input"<<endl;
        return NULL;
    }
    container * t;
    t = container_head_ptr;
    for(int i = 0; i < container_amount; i++){
        if((t->return_name()).compare(inName)==0){
            return t;
        }
        t=t->return_next_container();
    }
    cout << "can't find container named "<<inName<<endl;
    return NULL;
}

void HQ::print_all_container(){
    container * t;
    t = container_head_ptr;
    cout<<"--------------------------------------------------"<<endl;
    for(int i =0; i < container_amount; i ++){
        cout<<t->return_name()<<endl;
        t->print_all_customer();
        if(i<container_amount -1 ) cout<<" | "<<endl;
        //t->print_all_item();
        t = t->return_next_container();
    }
    cout<<"\n--------------------------------------------------"<<endl;
    
}

void HQ::print_head_container(){
    cout<<"this is HQ's print head"<<endl;
    cout<<"This is head of container list : "<<container_head_ptr->return_name()<<endl;
}

void HQ::delete_container(string inName){
    container * t, * prev;
    prev = NULL;
    t = container_head_ptr;
    bool found=false;
    for (int i=0;i< container_amount;i++){
        if((t->return_name()).compare(inName)!=0)
        {
            prev = t;
            t = t->return_next_container();
        }
        else
        {
            //if found
            found = true;
            if(((t->return_next_container()) == NULL)&&container_amount>1) //if delete last container
            {
                prev->set_next_container_ptr(NULL);
            } 
            else
            {
                if ((prev == NULL) && (container_amount >= 2)) //deleting head but more than one
                {
                    container_head_ptr = container_head_ptr->return_next_container();
                }
                else if((prev==NULL)&&(container_amount == 1))
                {
                    //last container 
                    container_head_ptr = NULL;
                }
                else 
                {
                    prev->set_next_container_ptr(t->return_next_container());
                }
            }
            delete(t);
            cout<<"\""<<inName<<"\" deleted"<<endl;
            container_amount--;
            cout<<"Container "<< HQ_name<<"\'s current container amount: "<<container_amount<<endl;
            break; // i don't know where i construct string from NULL to get that error
        }
    }
    
    if(!found){
        cout<<"Sorry, can't find the name (" << inName<<")"<<endl;
        cout<<"Container "<< HQ_name<<"\'s current container amount: "<<container_amount<<endl;
    }
}

//function for HQ
int HQ::add_container(string container_name, int size){
    //check valid id
    if((container_name.compare("no_name")==0)){
        cout<<"no item id input"<<endl;
        return 0;
    }
    
    container* new_container_ptr;
    new_container_ptr = new container(container_name);
    if (container_head_ptr==NULL){
        container_head_ptr = new_container_ptr;
    }
    else
    {
        new_container_ptr->set_next_container_ptr(container_head_ptr);
        container_head_ptr=new_container_ptr;
    }
    container_amount++;
    cout<<"container \""<<container_name<<"\" added to Container \""<<container_name<<"\""<<endl;
    cout<<"Container "<< container_name<<"\'s current container amount: "<<container_amount<<endl;
    return 1;
    
}



#endif