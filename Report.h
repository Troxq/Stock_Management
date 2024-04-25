#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
// #include "OrderFormatLL.h"

using namespace std;

void ReportCSV(const string);
void ReportStaff(string,const string);
void ReportManager(string, const string);

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

    string container_id_report;
    cout << "Please Select Container ID : ";
    cin >> container_id_report;
    string prefix = "Database/container_";
    string suffix = ".csv";

    string fullfilename = prefix + container_id_report + suffix;

    system("clear");
    ReportManager(container_id_report,fullfilename);
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

// void ReportCSV(const string filename) 
// {
//     cout << "Customer List: " << endl << endl;

//     ifstream file(filename);

//     vector<vector<string>> lines;
//     string line;
//     while (getline(file, line)) 
//     {
//         istringstream iss(line);
//         vector<string> lineData;
//         string token;
//         while (getline(iss, token, ',')) 
//         {
//             lineData.push_back(token);
//         }
//         lines.push_back(lineData);
//     }

//     sort(lines.begin(), lines.end(), SortingByOwner); // Sort lines by owner

//     for (const auto& lineData : lines) {
//         cout << "Owner: " << lineData[0] << endl; 
//         cout << "ID    | Name" << endl;
//         cout << "--------------------" << endl;
//         vector<string> mutableLineData = lineData; // Make a mutable copy
//         SortItemsInLine(mutableLineData);
//         for (size_t i = 1; i < mutableLineData.size(); i += 2) { 
//             cout << mutableLineData[i+1] << " | " << mutableLineData[i] << endl;
//         }
//         cout << endl;
//     }
//     cout << "====================" << endl;
//     cout << "Press Any Key and Enter to exit" << endl;

//     string exit_choice;
//     cin >> exit_choice;

//     file.close();
// }
