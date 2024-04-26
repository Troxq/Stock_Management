/*#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
// #include "OrderFormatLL.h"

using namespace std;

void ReportCSV(const string);
void ReportStaff(string,const string);
void ReportManager(string, const string);
void ContainerList();

class Node {
public:
    string owner;
    vector<pair<string, string>> items;
    Node* next;

    Node(const string& owner) : owner(owner), next(nullptr) {}
};

class ReportLinkedList {
private:
    Node* head;

public:
    ReportLinkedList() : head(nullptr) {}

    void insert(const string& owner, const vector<pair<string, string>>& items) {
        Node* new_node = new Node(owner);
        new_node->items = items;

        if (!head || head->items.empty() || head->items.front().first > items.front().first) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next && current->next->items.front().first < items.front().first) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << "Owner: " << current->owner << endl;
            cout << "Items:" << endl;
            for (const auto& item : current->items) {
                cout << " - ID: " << item.first << ", Name: " << item.second << endl;
            }
            cout << endl;
            current = current->next;
        }
    }

    ~ReportLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

void ReportCSV(const string filename) {
    cout << "Customer List: " << endl << endl;

    ifstream file(filename);

    ReportLinkedList list;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string owner;
        getline(iss, owner, ',');

        vector<pair<string, string>> items;
        string id, name;
        while (getline(iss, id, ',') && getline(iss, name, ',')) {
            items.push_back({id, name});
        }

        list.insert(owner, items);
    }

    list.print();

    cout << "====================" << endl;
    cout << "Press Any Key and Enter to exit" << endl;

    string exit_choice;
    cin >> exit_choice;

    file.close();
}

void ReportManager(string container_id_report,const string fullfilename)
{
    string line;
    cout << "|| Container ID : " << container_id_report << endl;
    cout << "====================" << endl;
    cout << "Manager: " << endl << endl;
    ifstream file("userdatabase.csv");      // open userdatabase file
    while (getline(file, line))
    {    
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        
        if (datarole == "Manager"  && dataid == container_id_report)
        {
            cout << datausername << endl;
        }
        
    }file.close();
    cout << "====================" << endl;
    
    ReportStaff(container_id_report,fullfilename);
}

void ReportStaff(string container_id_report,const string fullfilename)
{
    string line;
    cout << "Staff List: " << endl << endl;
    ifstream file("userdatabase.csv");
    while (getline(file, line))
    {
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        
        if (datarole == "Staff"  && dataid == container_id_report)
        {
            cout << datausername << endl;
        }
        
    }file.close();
    cout << "====================" << endl;
    ReportCSV(fullfilename);
}

void ReportMainMenu()
{
    system("clear");
    ContainerList();
    cout<<endl;
    string container_id_report;
    cout << "Please Select Container ID : ";
    cin >> container_id_report;
    string prefix = "Database/container_";
    string suffix = ".csv";

    string fullfilename = prefix + container_id_report + suffix;

    system("clear");
    ReportManager(container_id_report,fullfilename);
}

void ContainerList(){
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
        for(int i=0;i<HQ_data[1].size();i++){
            cout << "container id : " <<HQ_data[1][i] << endl;
        }
}

void ReportMainMenuforManager(int id_container)
{
    system("clear");

    string container_id_report = to_string(id_container);
    string prefix = "Database/container_";
    string suffix = ".csv";

    string fullfilename = prefix + container_id_report + suffix;

    system("clear");
    ReportStaff(container_id_report,fullfilename);
}*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void ReportCSV(const string);
void ReportStaff(string,const string);
void ReportManager(string, const string);
void ReportMainMenuforManager(int);
void ContainerList();

void split(const string& s, char delimiter, vector<string>& tokens) {
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
}

class Node {
public:
    string owner;
    vector<pair<string, string>> items;
    Node* next;

    Node(const string& owner) : owner(owner), next(nullptr) {}
};

class ReportLinkedList {
private:
    Node* head;

public:
    ReportLinkedList() : head(nullptr) {}

    void insert(const string& owner, const vector<pair<string, string>>& items) {
        Node* new_node = new Node(owner);
        new_node->items = items;

        if (!head || head->items.empty() || head->items.front().first > items.front().first) {
            new_node->next = head;
            head = new_node;
            return;
        }

        Node* current = head;
        while (current->next && current->next->items.front().first < items.front().first) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << "Owner: " << current->owner << endl;
            cout << "Items:" << endl;
            for (const auto& item : current->items) {
                cout << " - ID: " << item.first << ", Name: " << item.second << endl;
            }
            cout << endl;
            current = current->next;
        }
    }

    ~ReportLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

void ReportCSV(const string filename) {
    cout << "Customer List: " << endl << endl;

    ifstream file(filename);

    ReportLinkedList list;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string owner;
        getline(iss, owner, ',');

        vector<pair<string, string>> items;
        string id, name;
        while (getline(iss, id, ',') && getline(iss, name, ',')) {
            items.push_back({id, name});
        }

        sort(items.begin(), items.end()); // Sort items by ID

        list.insert(owner, items);
    }

    list.print();

    cout << "====================" << endl;
    cout << "Press Any Key and Enter to exit" << endl;

    string exit_choice;
    cin >> exit_choice;

    file.close();
}

void ContainerList(){
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

    /*for(int i=0; i<HQ_data[1].size(); i++) {
        cout << "Container ID : " << HQ_data[1][i] << endl;
    }*/

    vector<string> containerIDs; // Vector to store Container IDs

    for(int i=0; i<HQ_data[1].size(); i++) {
        containerIDs.push_back(HQ_data[1][i]); // Store Container IDs in the vector
    }

    // Sort the Container IDs
    sort(containerIDs.begin(), containerIDs.end());
        // Print the sorted Container IDs
    for(int i = 0; i < containerIDs.size(); i++) {
        cout << "Container ID : " << containerIDs[i] << endl;
    }
}

void ReportMainMenuforManager(int id_container)
{
    system("clear");

    string container_id_report = to_string(id_container);
    string prefix = "Database/container_";
    string suffix = ".csv";

    string fullfilename = prefix + container_id_report + suffix;

    system("clear");
    ReportStaff(container_id_report,fullfilename);
}
void ReportMainMenu()
{
    system("clear");
    ContainerList();
    cout<<endl;
    string container_id_report;
    cout << "Please Select Container ID : ";
    cin >> container_id_report;
    string prefix = "Database/container_";
    string suffix = ".csv";

    string fullfilename = prefix + container_id_report + suffix;

    system("clear");
    ReportManager(container_id_report,fullfilename);
}

void ReportManager(string container_id_report,const string fullfilename)
{
    string line;
    cout << "|| Container ID : " << container_id_report << endl;
    cout << "====================" << endl;
    cout << "Manager: " << endl << endl;
    ifstream file("userdatabase.csv");      // open userdatabase file
    while (getline(file, line))
    {    
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        
        if (datarole == "Manager"  && dataid == container_id_report)
        {
            cout << datausername << endl;
        }
        
    }file.close();
    cout << "====================" << endl;
    
    ReportStaff(container_id_report,fullfilename);
}

void ReportStaff(string container_id_report,const string fullfilename)
{
    string line;
    cout << "Staff List: " << endl << endl;
    ifstream file("userdatabase.csv");
    while (getline(file, line))
    {
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        
        if (datarole == "Staff"  && dataid == container_id_report)
        {
            cout << datausername << endl;
        }
        
    }file.close();
    cout << "====================" << endl;
    ReportCSV(fullfilename);
}