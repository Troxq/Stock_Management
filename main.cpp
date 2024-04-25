#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "HQ.h"

using namespace std;

string NextItemID; 

//load functions
vector<vector<string>> read_file_and_return_container_vector(const string&);
int load_file_into_HQptr(HQ *&);

//save function

vector<vector<string>> read_container_and_return_vector(string);
int save_file(HQ*);

int main()
{
    HQ * HQptr = new HQ("W",0);
    load_file_into_HQptr(HQptr);

    string con_id, name, item;
    int amount_item;
    cout << "Container ID : ";
    cin >> con_id;
    cout << "Customer Name : ";
    cin >> name;
    cout << "Item name : ";
    cin >> item;
    cout << "Amount : ";
    cin >> amount_item;
    
    for(int i = 0; i < amount_item; i++)
    {
        HQptr->HQ_add_item(con_id,name,NextItemID,item);
    }
    //HQptr->HQ_delete_item
    //load file()
    HQptr->print_all_container();


    //HQptr->print_all_container();

    
    save_file(HQptr);
    
    delete(HQptr);
    

}


int save_file(HQ* HQptr) {
    ofstream writingHQfile("HQ.csv");
    if(writingHQfile.is_open()){
        writingHQfile<<"id,"<<NextItemID<<","<<"\n";//store item id

        container * tempContainer;
        tempContainer= HQptr->return_container_head();
        int HQsize = HQptr->return_container_amount();
        for(int i = 0 ; i<HQsize; i++){
            writingHQfile<<tempContainer->return_name()<<",";

            string containerfilename = "container_"+tempContainer->return_name()+".csv";
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
    string HQfilename = "HQ.csv";
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
    string container_filename_prefix = "container_";
    string container_filename_suffix = ".csv";

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