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
<<<<<<< HEAD
}




//save function
/*

vector<vector<string>> read_container_and_return_vector(string container_id){
    string prefix = "container_";
    string suffix = ".csv";
    s
    ifstream file(filename);
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

int save_file(const string& containerId, const HQ* inHQptr) {
    string prefix = "container_";
    string suffix = ".csv";

    string filename = prefix + containerId + suffix;

    ofstream outfile(filename);

    if (!outfile) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return 0; // Return 0 to indicate failure
    }

    // Assuming you have appropriate getter methods in the HQ class
    vector<vector<string>> data = inHQptr->get_container_data(containerId);

    // Writing data to the CSV file
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            outfile << row[i];
            if (i != row.size() - 1) {
                outfile << ","; // Add comma between elements
            }
        }
        outfile << endl; // Newline after each row
    }

    outfile.close();
    return 1; // Return 1 to indicate success
}
*/


int main()
{
    HQ * HQptr = new HQ("W",0);
    load_file_into_HQptr(HQptr);

    cout<<"Next item id : "<<NextItemID<<endl;
    HQptr->HQ_add_item("1", "customer_1", NextItemID,"Macbook");
    HQptr->HQ_add_item("1", "customer_1", NextItemID,"Computer");

    HQptr->add_container("2");
    HQptr->HQ_add_customer("2", "got");
    HQptr->HQ_add_item("2", "got", NextItemID, "pencil");
    HQptr->HQ_delete_item("00001");

    //HQptr->HQ_delete_item
    //load file()
    HQptr->print_all_container();

    




    //delete old save file and create new / overwrite
    // -- here --
    //

    //HQptr->print_all_container();

    
    save_file(HQptr);
    
    delete(HQptr);
    

=======
>>>>>>> origin/Atom-Containers
}