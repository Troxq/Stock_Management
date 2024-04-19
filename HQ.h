#include <iostream>
#include "container.h"
#include <string>

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
        int add_container(string="no_name", int=0);
        void delete_container(string);
        void print_head_container();
        void print_all_container();
};

void HQ::print_all_container(){
    container * t;
    t = container_head_ptr;
    cout<<"--------------------------------------------------"<<endl;
    for(int i =0; i < container_amount; i ++){
        cout<<t->return_name();
        if(i<container_amount -1 ) cout<<" -> ";
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
                    cout<<"deleting head";
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
    if((container_name.compare("no_id")==0)){
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