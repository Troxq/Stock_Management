#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "HQ.h"

using namespace std;

//initial function
vector<vector<string>> read_file_and_return_container_vector(const string& filename) {
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

int load_file(string containerId, HQ *& inHQptr){
    string prefix = "container_";
    string suffix = ".csv";

    string container_name = prefix+containerId;
    string filename = prefix + containerId + suffix;

    vector<vector<string>> data = read_file_and_return_container_vector(filename);

    inHQptr->add_container(container_name,0);
    for(const auto& row : data){
        inHQptr->HQ_add_customer(container_name,row[0]);
        for(int i = 1; i < row.size(); i++){
            inHQptr->HQ_add_item(container_name, row[0],row[i]);
        }
        cout<<endl;
    }
    return 1;
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

int main()
{
    HQ * HQptr = new HQ("W",0);

    load_file("1", HQptr);

    //load file()
    
    


    
    /*
    HQptr->add_container("first_container");
    HQptr->HQ_add_customer("first_container", "Kenji");
    HQptr->HQ_add_customer("first_container", "Woody");
    HQptr->add_container("second_container");
    HQptr->add_container("third_container");

    HQptr->HQ_add_customer("second_container", "Kenji"); 
    HQptr->HQ_add_customer("third_container", "Woody");
    HQptr->HQ_delete_customer("third_container", "Woody");



    HQptr->HQ_add_item("first_container", "Kenji", "apple");
    HQptr->HQ_add_item("first_container", "Woody", "book");
    HQptr->HQ_add_item("third_container", "Woody", "hamburger");
    HQptr->HQ_add_item("third_container", "Woody", "computer");
    HQptr->HQ_add_item("second_container", "Kenji", "banana");

    HQptr->HQ_transfer_in_container("first_container", "Woody", "Kenji", "book");
    HQptr->HQ_transfer_over_container("Kenji", "first_container", "second_container", "apple");
    
    */
    HQptr->print_all_container();


    //delete old save file and create new / overwrite
    // -- here --
    //

    //HQptr->print_all_container();

    
    save_file();
    
    //delete(HQptr);
    

}