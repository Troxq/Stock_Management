// #ifndef OrderFormatLL_H
// #define OrderFormatLL_H

#include <string>
#include <iostream>
#include "OrderFormatNODE.h"
// #include "OrderFormatHEADLL.h"
using namespace std;

class LinkedList
{
    string LinkedList_name; 
    NODE * NODE_head_ptr;
    LinkedList *next;
    LinkedList *back;
    string status;
    int idContainer;
    int size;

    // add NODE name then store
    // add LinkedList later
    public:
        LinkedList(string="default_LinkedList",int=0, string="Pending", int=1);
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
    /*
    .add(id);
    .searchid(id) //loop every NODE
    */    
};

LinkedList::LinkedList(string inName,int inSize, string s, int id){
    LinkedList_name=inName; 
    size=inSize;
    NODE_head_ptr = NULL;
    next = NULL;
    back = NULL;
    status = s;
    idContainer = id;
}

int LinkedList::return_idContainer()
{
    return idContainer;
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
    cout << "eiei" << endl;
    if (t != NULL)
    {
        system("clear");
        cout << "Owner name : " << LinkedList_name << endl;
        cout << "Container ID : " << idContainer << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (; t != NULL; t = t->return_next_NODE())
        {
            cout << "  name : " << t->return_name() << "  " << "amount : " << t->return_amount() << endl;
        }
        cout << "-------------------------------------------------------------" << endl;
    }
    else
    {
        cout << "|----------------------------------------------------------------|" << endl;
        cout << "|                      Don't have any Product                    |" << endl;
        cout << "|----------------------------------------------------------------|" << endl;
    }
    cout << "size = " << size << endl;
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
        cout << "-------------------------------------------------------------" << endl;
        for (; t != NULL; t = t->return_next_NODE())
        {
            cout << "  name : " << t->return_name() << "  " << "amount : " << t->return_amount() << endl;
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
        myfile << idContainer << "," << status << "," << LinkedList_name << "," << size;
        // cout << "size = " << size << endl;
        for (int i = size; i > 0; i--)
        {
            // cout << "eiei" << endl;
            // cout << "i : " << i << endl;
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

// void LinkedList::save_data(string nameFile, int status) {
//     ifstream infile(nameFile);
//     ofstream outfile("temp.csv"); // Create a temporary file to store modified data

//     bool found = false; // Flag to track if data is found in the file

//     // Read each line from the file
//     string line;
//     while (getline(infile, line)) {
//         // Split the line into fields
//         stringstream ss(line);
//         vector<string> fields;
//         string field;
//         while (getline(ss, field, ',')) {
//             fields.push_back(field);
//         }

//         // Check if the line matches the data you want to save
//         if (fields.size() >= 3 && fields[1] == LinkedList_name && stoi(fields[2]) == size) {
//             // If the line matches, replace the status with the new status
//             fields[0] = to_string(status);
//             found = true;
//         }

//         // Write the modified or original line to the temporary file
//         for (size_t i = 0; i < fields.size(); ++i) {
//             outfile << fields[i];
//             if (i < fields.size() - 1) outfile << ",";
//         }
//         outfile << endl;
//     }

//     infile.close();
//     outfile.close();

//     // If the data was not found in the file, append it to the end
//     if (!found) {
//         outfile.open(nameFile, ios_base::app);
//         outfile << status << "," << LinkedList_name << "," << size;
//         NODE *t = NODE_head_ptr;
//         while (t != nullptr) {
//             outfile << "," << t->return_name() << "," << t->return_amount();
//             t = t->return_next_NODE();
//         }
//         outfile << endl;
//         outfile.close();
//         cout << "New data has been appended and saved." << endl;
//     } else {
//         // Rename the temporary file to replace the original file
//         remove(nameFile.c_str());
//         rename("temp.csv", nameFile.c_str());
//         cout << "Data has been updated and saved." << endl;
//     }

//     system("clear");
//     cout << R"(
//                     sending...
//     )" << endl;
//     sleep(5);
// }

void LinkedList::save_data(string nameFile, int status) {
    ifstream infile(nameFile);
    ofstream outfile("temp.csv"); // Create a temporary file to store modified data

    bool found = false; // Flag to track if data is found in the file

    if (infile.is_open() && outfile.is_open()) { // Check if both files are opened successfully
        // Read each line from the file
        string line;
        while (getline(infile, line)) {
            // Split the line into fields
            stringstream ss(line);
            vector<string> fields;
            string field;
            while (getline(ss, field, ',')) {
                fields.push_back(field);
            }

            // Check if the line matches the data you want to save
            if (fields.size() >= 4 && fields[2] == LinkedList_name && stoi(fields[3]) == size) {
                // If the line matches, replace the status with the new status
                fields[1] = to_string(status);
                found = true;
            }

            // Write the modified or original line to the temporary file
            for (size_t i = 0; i < fields.size(); ++i) {
                outfile << fields[i];
                if (i < fields.size() - 1) outfile << ",";
            }
            outfile << endl;
        }

        infile.close();
        outfile.close(); // Close both files

        // If the data was not found in the file, append it to the end
        if (!found) {
            outfile.open(nameFile, ios_base::app);
            outfile << idContainer << "," << status << "," << LinkedList_name << "," << size;
            NODE *t = NODE_head_ptr;
            while (t != nullptr) {
                outfile << "," << t->return_name() << "," << t->return_amount();
                t = t->return_next_NODE();
            }
            outfile << endl;
            outfile.close();
            cout << "New data has been appended and saved." << endl;
        } else {
            // Rename the temporary file to replace the original file
            remove(nameFile.c_str());
            sleep(3);
            rename("temp.csv", nameFile.c_str());
            cout << "Data has been updated and saved." << endl;
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

