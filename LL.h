#ifndef LL_H
#define LL_H

#include <string>
#include <iostream>
#include "NODE.h"
using namespace std;

class LinkedList{
    string LinkedList_name; 
    NODE * NODE_head_ptr=NULL;
    int size;

    // add NODE name then store
    // add LinkedList later
    public:
        LinkedList(string="default_LinkedList",int=0);
        void LinkedList_show_name(); // how many items;
        void add_NODE(string);
        void delete_NODE(string);
        void print_head_NODE();

        void add_NODE(string, int); // GOT : for sendorder
        void displayAll(); // GOT : for display all node in sendorder
        void delete_NODE_Got(string); // GOT : for sendorder
        void save_data(); // GOT : for save data sendorder
    /*
    .add(id);
    .searchid(id) //loop every NODE
    */    
};

LinkedList::LinkedList(string inName,int inSize){
    LinkedList_name=inName; 
    size=inSize;
}

void LinkedList::LinkedList_show_name(){
    cout<<"LinkedList name: "<< LinkedList_name<<endl;
}

void LinkedList::add_NODE(string NODE_name){
    NODE* new_NODE_ptr;
    new_NODE_ptr = new NODE(NODE_name);
    if (NODE_head_ptr==NULL){
        NODE_head_ptr = new_NODE_ptr;
    }else{
        new_NODE_ptr->set_next_NODE_ptr(NODE_head_ptr);
        NODE_head_ptr=new_NODE_ptr;
    }
    size++;
    cout<<"NODE \""<<NODE_name<<"\" added"<<endl;
    cout<<"Current NODE Size : "<<size<<endl;
    
};

void LinkedList::add_NODE(string NODE_name, int amount)
{
    NODE* new_NODE_ptr;
    new_NODE_ptr = new NODE(NODE_name, amount);
    if (NODE_head_ptr==NULL)
    {
        NODE_head_ptr = new_NODE_ptr;
    }
    else
    {
        new_NODE_ptr->set_next_NODE_ptr(NODE_head_ptr);
        NODE_head_ptr=new_NODE_ptr;
    }
    size++;
    // cout<<"NODE \""<<NODE_name<<"\" added"<<endl;
    // cout<<"Current NODE Size : "<<size<<endl;
    
};

void LinkedList::print_head_NODE(){
    cout<<"This is head of NODE list : "<<NODE_head_ptr->return_name()<<endl;
}

void LinkedList::delete_NODE(string inName){
    NODE * t, * prev;
    prev = NULL;
    t = NODE_head_ptr;
    bool found=false;
    for (int i=0;i< size;i++){
        if((t->return_name()).compare(inName)!=0){
            prev = t;
            t = NODE_head_ptr->return_next_NODE();
        }else{
            //if found
            found = true;
            if(( t->return_next_NODE() == NULL)&&size>1) //if delete last node
            {
                prev->set_next_NODE_ptr(NULL);
                delete (t);
            } 
            else
            {
                if (prev == NULL && size >= 2) //deleting head but more than one
                {
                    NODE_head_ptr = NODE_head_ptr->return_next_NODE();
                    delete t;
                }
                else if(size == 1)
                {
                    //last NODE 
                    NODE_head_ptr = NULL;
                    delete (t);
                }
                else if((prev!= NULL) && (size>=2))
                {
                    cout<<"else case"<<endl;
                    NODE_head_ptr = NULL;
                    prev->set_next_NODE_ptr(t->return_next_NODE());
                    size--;
                    delete(t);
                }
            }
            cout<<"\""<<inName<<"\" deleted"<<endl;
            size--;
            cout<<"remaining NODE Size: "<<size<<endl;
        }
    }
    if(!found){
        cout<<"Sorry, can't find Node (" << inName<<")"<<endl;
    }
}

void LinkedList::delete_NODE_Got(string nameProduct)
{
    NODE *currentPtr, *previousPtr;
    currentPtr = NODE_head_ptr;
    previousPtr = NULL;

    if (size > 0)
    {
        if (currentPtr->return_name() == nameProduct)
        {
            NODE_head_ptr = NODE_head_ptr->return_next_NODE();
            cout << currentPtr->return_name() << " has been deleted" << endl;
            free(currentPtr);
            size -= 1;
        }
        else
        {
            for (int len = size - 1; len > 0 && currentPtr->return_name() != nameProduct; len--)
            {
                previousPtr = currentPtr;
                currentPtr = currentPtr->return_next_NODE();
            }
            
            NODE *t = currentPtr;
            currentPtr = currentPtr->return_next_NODE();
            previousPtr->set_next_NODE_ptr(currentPtr);
            cout << t->return_name() << " has been deleted" << endl;
            free(t);
            size -= 1;
        }
    }
}

void LinkedList::displayAll()
{
    NODE *t = NODE_head_ptr;
    if (t != NULL)
    {
        system("clear");
        cout << "-------------------------------------------------------------" << endl;
        for (; t != NULL; t = t->return_next_NODE())
        {
            cout << "  name : " << t->return_name() << "  " << "amount : " << t->return_amount() << endl;
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    cout << "size = " << size << endl;

}

void LinkedList::save_data()
{
    ofstream myfile;
    NODE *t = NODE_head_ptr;
    myfile.open("OrderManagerDatabase.csv", ios::app);
    if (myfile.is_open()) {
        myfile << LinkedList_name << "," << size;
        for (int i = size; i > 0; i--)
        {
            myfile << "," << t->return_name() << "," << t->return_amount();
            t = t->return_next_NODE();
        }
        myfile << endl;
        cout << "Data has been appended and saved." << endl;
        myfile.close(); 
    } else {
        cout << "Unable to open file!" << endl;
    }
}


#endif

