#include <iostream>
#include "container.h"
#include "check.h"
#include <string>
#include <vector>

#ifndef HQ_H
#define HQ_H


using namespace std;

extern string NextItemID;

class HQ{
    string HQ_name;
    int container_amount; //linked list property
    container * container_head_ptr=NULL; //linked list property

    public:
        HQ(string inName="no_input",int inAmount=0){
            HQ_name = inName;
            container_amount = inAmount;
        };
        ~HQ();

        //for HQ
        vector<vector<string>> read_and_return_container_vector(container*);
        int add_container(string="no_input", int=0);
        int delete_container(string="no_input");
        void print_all_container();
        container * return_container_pointer(string="no_input");
        int show_customer_in_container(string="no_input");
        void delete_all_container();
        int return_container_amount();
        container * return_container_head();

        //for Manager & Staff
        int HQ_transfer_in_container(string="no_input",string="no_input", string="no_input", string="no_input"); //owner, item, receiver
        int HQ_transfer_over_container(string="no_input", string="no_input", string="no_input", string="no_input");//customer, origin container, destination container, item
        int HQ_add_customer(string="no_input",string="no_input"); //need container and actual customer name 
        int HQ_delete_customer(string="no_input", string="no_input"); //need container and actual customer name 
        int HQ_transfer_item(string="no_input", string="no_input", string="no_input",string ="no_input");
        int HQ_add_item(string="no_input", string="no_input", string="no_input",string ="no_input"); //need container, customer name, item name
        int HQ_delete_item(string="no_input");
};

container * HQ::return_container_head(){
    return container_head_ptr;
}

int HQ::HQ_delete_item(string item_id){
    // cus_name = (return_customer_pointer(item_id))->return_name();

    // container * target = return_container_pointer((return_customer_pointer(item_id))->return_name());

    // container * target = return_container_pointer(container_name)->return_container_pointer(item_id)->return_name();
    // target->customer_delete_item(item_id);
    cout<<"==== item delete ====" << endl;
    return 1;
}

int HQ::return_container_amount(){
    return container_amount;
}

int HQ::HQ_transfer_in_container(string container_name,string owner_name, string receiver_name, string item_id){
    if(check_no_input(4,container_name, owner_name, receiver_name, item_id)){
        //if wrong input
        return 0;
    }

    container * container_ptr = return_container_pointer(container_name);
    cout<<"get container ptr"<<endl;
    if(container_ptr){
        if(container_ptr->container_transfer_in_container(owner_name, receiver_name, item_id)){
            return 1;
        }
    }
    cout<<"can't transfer"<<endl;
    return 0;
}

int HQ::HQ_transfer_over_container(string customer_name, string origin_container_name, string des_container_name, string item_id){
    if(check_no_input(4,customer_name, origin_container_name, des_container_name, item_id)){
        //if wrong input
        return 0;
    }

    container * origin_ptr = return_container_pointer(origin_container_name);
    container * des_ptr = return_container_pointer(des_container_name);
    
    //check valid container_pointer
    if(!origin_ptr || !des_ptr){
        // can't find one or both container, return_container_pointer() already cout error & return NULL
        return 0;
    }


    item * moved_item = (origin_ptr->return_customer_pointer(customer_name))->return_item_pointer(item_id);
    string itemname = moved_item->return_name();
    if(origin_ptr->customer_delete_item(customer_name,item_id)){
        des_ptr->customer_transfer_item_in(customer_name,item_id,itemname);
        cout<<"transfer "<<item_id<<" complete"<<endl;
        return 1;
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
    if(check_no_input(2, customer_name, container_name)){
        return 0;
    }

    container * t = return_container_pointer(container_name);
    //check valid pointer
    if(!t){
        //can't find pointer
        return 0;
    }
    
    if(t->delete_customer(customer_name)) return 1;
    return 0;
}

int HQ::HQ_add_item(string container_name, string customer_name, string NextItemID,string item_name){
    if(check_no_input(3, container_name, customer_name, item_name)){
        //wrong input
        return 0;
    }

    //get container pointer called "t"
    container * t = return_container_pointer(container_name);
    if(!t){
        //can't find pointer
        return 0;
    }


    if(t->customer_add_item(customer_name,NextItemID,item_name)){
        return 1;
    }
    return 0;

}

int HQ::HQ_transfer_item(string container_name, string customer_name,string item_id, string item_name){
    if(check_no_input(4, container_name, customer_name, item_name, item_id)){
        return 0;
    }

    container * t = return_container_pointer(container_name);
    if(!t){
        //can't find pointer
        return 0;
    }

    if(t->customer_transfer_item_in(customer_name,item_id,item_name)){
        return 1;
    }
    return 0;

}

int HQ::show_customer_in_container(string container_name){
    if(check_no_input(1, container_name)){
        return 0;
    }

    container * t = return_container_pointer(container_name);
    if(!t){
        cout<<"no container name";
        return 0;
    }

    t->print_all_customer();
    return 1;
}

int HQ::HQ_add_customer(string container_name, string customer_name){
    if(check_no_input(2,container_name, customer_name)){
        return 0;
    }

    container * t = return_container_pointer(container_name);
    if(!t){
        return 0;
    }
    t->add_customer(customer_name);
    return 1;
}

container * HQ::return_container_pointer(string inName){
    if(check_no_input(1, inName)){
        return 0;
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
    cout<<"printing all"<<endl;
    for(int i =0; i < container_amount; i ++){
        cout<<t->return_name()<<endl;
        t->print_all_customer();
        if(i<container_amount -1 ) cout<<" | "<<endl;
        t = t->return_next_container();
    }
    cout<<"--------------------------------------------------\n"<<endl;
    
}

int HQ::delete_container(string inName){
    if(check_no_input(1,inName)){
        return 0;
    }

    container * t, * prev;
    prev = NULL;
    t = container_head_ptr;
    if(!t){
        cout<<"There is no container in HQ "<<endl;
        return 0;
    }
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
            return 1; // i don't know where i construct string from NULL to get that error
        }
    }
    
    if(!found){
        cout<<"Sorry, can't find the name (" << inName<<")"<<endl;
        cout<<"Container "<< HQ_name<<"\'s current container amount: "<<container_amount<<endl;
    }
    return 0;
}

//function for HQ
int HQ::add_container(string container_name, int size){
    if(check_no_input(1,container_name)){
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
    // cout<<"container \""<<container_name<<"\" added"<<endl;
    // cout<<"current container amount: "<<container_amount<<endl;
    return 1;
}



#endif