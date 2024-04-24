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
    

}