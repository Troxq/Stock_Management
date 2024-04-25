#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "HQ.h"
#include "Log.h"

using namespace std;

string NextItemID; 

//load functions
vector<vector<string>> read_file_and_return_container_vector(const string&);
int load_file_into_HQptr(HQ *&);

//save function
vector<vector<string>> read_container_and_return_vector(string);
int save_file(HQ*);

void inputproduct(int);
void exportproduct(int);
void transferproduct(int);
bool isNameExists(string , string) ;

void inputproduct(int role_id, string username, string role)
{
    HQ * HQptr = new HQ("W",0);
    
    load_file_into_HQptr(HQptr);

    string input_container_id = to_string(role_id);
    string input_customer, input_item;
    int input_amount;
    cout << "===================================" << endl;
    cout << "=============Import================" << endl;
    cout << "Container ID :" << role_id << endl;
    cout << "Input Customer Name : ";
    cin >> input_customer;
    cout << "Input Item Name : ";
    cin >> input_item;
    cout << "Input Amount of Item : ";
    cin >> input_amount;

    if(isNameExists(input_container_id,input_customer))
    {
        for (int i = 0; i < input_amount; i++)
        {
            HQptr->HQ_add_item(input_container_id,input_customer,NextItemID,input_item);
            import_prod(username, role, input_container_id, to_string(stoi(NextItemID)-1));

        }
    }
    else
    {
        HQptr->HQ_add_customer(input_container_id,input_customer); // add customer if they didn't exist
        for (int i = 0; i < input_amount; i++)
        {
            HQptr->HQ_add_item(input_container_id,input_customer,NextItemID,input_item);
            import_prod(username, role, input_container_id, NextItemID);
        }
    }
    
    save_file(HQptr);

    delete(HQptr);
}

void exportproduct(int role_id, string username, string role)
{
    HQ * HQptr = new HQ("W",0);
    
    load_file_into_HQptr(HQptr);

    string input_container_id = to_string(role_id);
    string input_customer, input_item, input_item_id;

    cout << "===================================" << endl;
    cout << "=============Export================" << endl;
    cout << "Container ID :" << role_id << endl;
    cout << "Input Customer Name : ";
    cin >> input_customer;
    cout << "Input Item ID : ";
    cin >> input_item_id;

    if(HQptr->delete_item_HQ(input_container_id,input_customer,input_item_id) == 1)
    {
        export_prod(username, role, input_container_id, input_item_id);
    }

    save_file(HQptr);

    delete(HQptr);
}

void transferproduct(int role_id, string username, string role)
{
    HQ * HQptr = new HQ("W",0);
    
    load_file_into_HQptr(HQptr);

    string input_container_id = to_string(role_id);
    string input_container_id_2;
    string input_customer, input_receiver, input_item, input_item_id;

    int input_choice;

    cout << "===================================" << endl;
    cout << "============Transfer===============" << endl;
    cout << "Container ID :" << role_id << endl;
    cout << "Transfer Items inside or outside Container" << endl;
    cout << "Choose (1. inside 2. outside) : ";
    cin >> input_choice;
    if (input_choice == 1)
    {   
        cout << "+++++Transfer Inside Container+++++" << endl;
        cout << "Input Customer Name : ";
        cin >> input_customer;
        cout << "Input Reciever Name : ";
        cin >> input_receiver;
        cout << "Input Item ID : ";
        cin >> input_item_id;

        HQptr->HQ_transfer_in_container(input_container_id,input_customer,input_receiver,input_item_id);
        transfer_prod(username, role, input_item_id, input_container_id, input_customer, input_receiver);

    }
    else
    {
        cout << "+++++Transfer Outside Container+++++" << endl;
        cout << "Input Customer Name : ";
        cin >> input_customer;
        cout << "Input Container ID to transfer : ";
        cin >> input_container_id_2;
        cout << "Input Item ID : ";
        cin >> input_item_id;
        
        if(isNameExists(input_container_id_2,input_customer))
        {
            HQptr->HQ_transfer_over_container(input_customer,input_container_id,input_container_id_2,input_item_id);
            transfer_prod(username, role, input_item_id, input_container_id, input_container_id_2, "None");
        }
        else
        {
            HQptr->HQ_add_customer(input_container_id_2,input_customer); // add customer if they didn't exist
            HQptr->HQ_transfer_over_container(input_customer,input_container_id,input_container_id_2,input_item_id);
            transfer_prod(username, role, input_item_id, input_container_id, input_container_id_2, "None");
        }
    }
    
    save_file(HQptr);

    delete(HQptr);
}

bool isNameExists(string id_container, string name) 
{
    string prefix = "Database/container_";
    string midfix = id_container;
    string suffix = ".csv";

    string filename = prefix + midfix + suffix;

    ifstream file(filename);

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string currentName;
        if (getline(iss, currentName, ',') && currentName == name) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


int save_file(HQ* HQptr) {
    ofstream writingHQfile("Database/HQ.csv");
    if(writingHQfile.is_open()){
        writingHQfile<<"id,"<<NextItemID<<","<<"\n";//store item id

        container * tempContainer;
        tempContainer= HQptr->return_container_head();
        int HQsize = HQptr->return_container_amount();
        for(int i = 0 ; i<HQsize; i++){
            writingHQfile<<tempContainer->return_name()<<",";
            string preprefix = "Database/";
            string containerfilename = preprefix + "container_" + tempContainer->return_name()+".csv";
            ofstream writingContainerfile(containerfilename);
            if(writingContainerfile.is_open()){

                customer * tempCustomer = tempContainer->return_customer_head();
                for(int j = 0; j < tempContainer->return_customer_amount();j++){
                    writingContainerfile<<tempCustomer->return_name()<<",";

                    item* tempItem = tempCustomer->return_item_head();
                    for(int k = 0 ; k < tempCustomer->return_item_amount();k++){
                        writingContainerfile<<tempItem->return_id()<<","<<tempItem->return_name()<<",";
                        tempItem = tempItem->return_next_item();
                    }
                    writingContainerfile<<"\n";

                    tempCustomer = tempCustomer->return_next_customer(); ////move tempcustomer
                }
            }
            else {
                std::cerr << "Unable to open file: " << containerfilename << std::endl;
            }
            cout<<"Container "<<tempContainer->return_name()<<"\'s data are stored in file \""<<containerfilename<<"\""<<endl;
            writingContainerfile.close();

            tempContainer = tempContainer->return_next_container(); //move tempcontainer
        }
        cout<<"write all changes into \"HQ.csv\" file"<<endl;
        writingHQfile.close();
        return 1;
    }
    std::cerr << "Unable to open file: HQ.csv" << std::endl;
    return 0;
    

}

vector<vector<string>> read_file_and_return_container_vector(const string& container_filename) {
    ifstream file(container_filename);
    vector<vector<string>> data;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    file.close();
    
    return data;

}


int load_file_into_HQptr(HQ *& inHQptr){
    string HQfilename = "Database/HQ.csv";
    ifstream file(HQfilename);
    vector<vector<string>> HQ_data;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        HQ_data.push_back(row);
    }

    file.close();

    //get current id
    NextItemID = (HQ_data[0][1]);
    
    string container_filename_prefix = "Database/container_";
    string container_filename_suffix = ".csv";
    if(HQ_data.size()==1){
        return 1;
    }
    for(int i = 0; i < HQ_data[1].size();i++){
        string container_name = HQ_data[1][i];
        //cout<<"container_name is "<< container_name<<endl;
        inHQptr->add_container(container_name);
        string full_container_filename = container_filename_prefix + container_name + container_filename_suffix;
        vector<vector<string>> container_data = read_file_and_return_container_vector(full_container_filename);
        for(const auto& row : container_data){
            inHQptr->HQ_add_customer(container_name, row[0]);
            for(int i = 1; i < row.size(); i+=2){
                inHQptr->HQ_transfer_item(container_name, row[0], row[i], row[i+1]); //container_name, customer_name, item_id, item_name
            }
        }
    }
    return 1;
}