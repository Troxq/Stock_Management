// #ifndef OrderFormatLL_H
// #define OrderFormatLL_H

#include <string>
#include <iostream>
#include <sstream>
#include "OrderFormatNODE.h"
// #include "OrderFormatHEADLL.h"
using namespace std;

string display_action(int duty)
{
    switch (duty)
    {
        case 1 : return "Import";
        case 2 : return "Export";
        case 3 : return "Transfer";
    }
    return "No Action";
}


class LinkedList
{
    string LinkedList_name;
    NODE * NODE_head_ptr;
    LinkedList *next;
    LinkedList *back;
    string status;
    int idContainer;
    int size;
    int duty;
    int sendIdContainer;

    // add NODE name then store
    // add LinkedList later
    public:
        LinkedList(string="default_LinkedList",int=0, string="Pending", int = 1, int = 0, int = 0);
        ~LinkedList();
        void LinkedList_show_name(); // how many items;
        void add_NODE(string);
        void delete_NODE(string);
        void print_head_NODE();

        void add_NODE(string, int); // GOT : for sendorder
        void displayAll(); // GOT : for display all node in sendorder
        void delete_NODE_Got(string); // GOT : for sendorder
        void displayOrderStatus();
        void save_data(string, int = 0); // GOT : for save data sendorder
        void save_data_HQ(string, int = 0);
        void save_data_HQ_transfer(string nameFile, int status);
        int load_data_for_check(string nameFile, string);
        // string load_status(string); // GOT : for load data order
        void set_name(string); // GOT : for load data order
        // void set_size(int); // GOT : for load data order
        void set_status();
        void insert(LinkedList *&);
        LinkedList* move_next();
        LinkedList* move_back();
        void set_next_LinkList_ptr(LinkedList*);
        void set_back_LinkList_ptr(LinkedList*);
        string return_name();
        int return_size();
        NODE* return_node();
        int return_idContainer();
        int return_duty();
        int return_status();
        int return_sendIdContainer();    /*
    .add(id);
    .searchid(id) //loop every NODE
    */    
};

LinkedList::LinkedList(string inName,int inSize, string s, int id, int d, int sendId){
    LinkedList_name=inName; 
    size=inSize;
    NODE_head_ptr = NULL;
    next = NULL;
    back = NULL;
    status = s;
    idContainer = id;
    duty = d;
    sendIdContainer = sendId;
}

LinkedList::~LinkedList()
{
    NODE* t_NODE;

    for (int i = 0; i < size; i++)
    {
        t_NODE = NODE_head_ptr;
        NODE_head_ptr = NODE_head_ptr->return_next_NODE();
        delete t_NODE;
    }
}

int LinkedList::return_idContainer()
{
    return idContainer;
}

int LinkedList::return_sendIdContainer()
{
    return sendIdContainer;
}

int LinkedList::return_status()
{
    if (status == "Pending")
    {
        return 0;
    }
    else if (status == "Confirm")
    {
        return 1;
    }
    else if (status == "Finish")
    {
        return 2;
    }
    return 0;
}

int LinkedList::return_duty()
{
    return duty;
}

string LinkedList::return_name()
{
    return LinkedList_name;
}

int LinkedList::return_size()
{
    return size;
}

NODE* LinkedList::return_node()
{
    return NODE_head_ptr;
}

int LinkedList::load_data_for_check(string nameFile, string nameCustomer)
{
    ifstream fin;

    fin.open(nameFile);

    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        stringstream s(line);
        
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (row[4] == nameCustomer)
        {
            cout << "Error: Please don't input same customer name" << endl;
            sleep(1);
            fin.close();
            return 1;
        }
    }
    return 0;
}

void LinkedList::set_next_LinkList_ptr(LinkedList* next_LinkList_address){
    next = next_LinkList_address;
}

void LinkedList::set_back_LinkList_ptr(LinkedList* back_LinkList_address)
{
    back = back_LinkList_address;
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
};

void LinkedList::add_NODE(string NODE_name, int amount)
{
    NODE* new_NODE_ptr;

    NODE* t = NODE_head_ptr;
    for (;t != NULL; t = t->return_next_NODE())
    {
        if (t->return_name() == NODE_name)
        {
            if (duty == 1)
                cout << "Error: Please don't input same name" << endl;
            else
                cout << "Error: Please don't input same ID" << endl;
            sleep(1);
            return ;
        }
    }

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
            found = true;
            if(( t->return_next_NODE() == NULL)&&size>1) 
            {
                prev->set_next_NODE_ptr(NULL);
                delete (t);
            } 
            else
            {
                if (prev == NULL && size >= 2) 
                {
                    NODE_head_ptr = NODE_head_ptr->return_next_NODE();
                    delete t;
                }
                else if(size == 1)
                {
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
            size--;
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
            
            if (currentPtr->return_name() == nameProduct && currentPtr != NULL)
            {
                NODE *t = currentPtr;
                currentPtr = currentPtr->return_next_NODE();
                previousPtr->set_next_NODE_ptr(currentPtr);
                cout << t->return_name() << " has been deleted" << endl;
                free(t);
                size -= 1;
            }
            else
            {
                cout << "Error: Don't have that product" << endl;
                sleep(1);
            }
            
        }
        
    }
    else
    {
        cout << "Error: Don't have that product" << endl;
        sleep(1);
    }
}

void LinkedList::displayAll()
{
    NODE *t = NODE_head_ptr;
    if (t != NULL)
    {
        system("clear");
        cout << "Owner name : " << LinkedList_name << endl;
        cout << "Container ID : " << idContainer << endl;
        if (sendIdContainer > 0)
        {
            cout << "Transfer to container ID : " << sendIdContainer << endl;
        }
        cout << "Action : " << display_action(duty) << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (; t != NULL; t = t->return_next_NODE())
        {
            if (duty == 1)
            {
                if (t->return_amount() > 0)
                    cout << "  Name product : " << t->return_name() << "   Amount : " << t->return_amount() << endl;
                else
                    cout << "  Name product : " << t->return_name() << endl;
            }
            else
            {
                if (t->return_amount() > 0)
                    cout << "  ID product : " << t->return_name() << "  " << "   Amount : " << t->return_amount() << endl;
                else
                    cout << "  ID product : " << t->return_name() << endl;
            }
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "Owner name : " << LinkedList_name << endl;
        cout << "Container ID : " << idContainer << endl;
        if (sendIdContainer > 0)
        {
            cout << "Transfer to container ID : " << sendIdContainer << endl;
        }
        cout << "Action : " << display_action(duty) << endl;
        cout << "|----------------------------------------------------------------|" << endl;
        cout << "|                      Don't have any Product                    |" << endl;
        cout << "|----------------------------------------------------------------|" << endl;
    }
}

void LinkedList::displayOrderStatus()
{
    NODE *t = NODE_head_ptr;
    // cout << "eiei" << endl;
    if (t != NULL)
    {
        system("clear");
        cout << "Owner name : " << LinkedList_name << endl;
        cout << "Order status : " << status << endl;
        cout << "Container ID : " << idContainer << endl;
        if (sendIdContainer > 0)
        {
            cout << "Transfer to container ID : " << sendIdContainer << endl;
        }
        cout << "Action : " << display_action(duty) << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (; t != NULL; t = t->return_next_NODE())
        {
            if (duty == 1)
            {
                if (t->return_amount() > 0)
                    cout << "  Name product : " << t->return_name() << "  " << "Amount : " << t->return_amount() << endl;
                else
                    cout << "  Name product : " << t->return_name() << endl;
            }
            else
            {
                if (t->return_amount() > 0)
                    cout << "  ID product : " << t->return_name() << "  " << "Amount : " << t->return_amount() << endl;
                else
                    cout << "  ID product : " << t->return_name() << endl;   
            }
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "|----------------------------------------------------------------|" << endl;
        cout << "|                       Don't have any Order.                    |" << endl;
        cout << "|----------------------------------------------------------------|" << endl;
    }
}

void LinkedList::save_data_HQ(string nameFile, int status)
{
    ofstream myfile;
    NODE *t = NODE_head_ptr;
    myfile.open(nameFile, ios::app);
    if (myfile.is_open()) {
        myfile << sendIdContainer << "," << duty << "," << idContainer << "," << status << "," << LinkedList_name << "," << size;
        // cout << "size = " << size << endl;
        for (int i = size; i > 0; i--)
        {
            // cout << "eiei" << endl;
            // cout << "i : " << i << endl;
            myfile << "," << t->return_name() << "," << t->return_amount();
            t = t->return_next_NODE();
        }
        myfile << endl;
        // cout << "Data has been appended and saved." << endl;
        myfile.close(); 
    } else {
        cout << "Unable to open file!" << endl;
    }
}

void LinkedList::save_data(string nameFile, int status) {
    ifstream infile(nameFile);
    ofstream outfile("temp.csv"); 

    bool found = false; 

    if (infile.is_open() && outfile.is_open()) { 
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            vector<string> fields;
            string field;
            while (getline(ss, field, ',')) {
                fields.push_back(field);
            }

            if (fields.size() >= 4 && fields[4] == LinkedList_name && stoi(fields[5]) == size) {
                fields[3] = to_string(status);
                found = true;
            }

            for (size_t i = 0; i < fields.size(); ++i) {
                outfile << fields[i];
                if (i < fields.size() - 1) outfile << ",";
            }
            outfile << endl;
        }

        infile.close();
        outfile.close();

        if (!found) {
            outfile.open(nameFile, ios_base::app);
            outfile << sendIdContainer << "," << duty << "," << idContainer << "," << status << "," << LinkedList_name << "," << size;
            NODE *t = NODE_head_ptr;
            while (t != nullptr) {
                outfile << "," << t->return_name() << "," << t->return_amount();
                t = t->return_next_NODE();
            }
            outfile << endl;
            outfile.close();
        } else {
            remove(nameFile.c_str());
            cout << R"(
                        sending ...
            )";
            sleep(3);
            rename("temp.csv", nameFile.c_str());
        }
    } else {
        cout << "Unable to open files!" << endl;
    }
}

void LinkedList::insert(LinkedList *&x)
{
    x->next = this;
    if (this != NULL)
        this->back = x;
}

LinkedList* LinkedList::move_next()
{
    return next;
}

LinkedList* LinkedList::move_back()
{
    return back;
}

// #endif

