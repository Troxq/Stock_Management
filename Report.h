#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void ReportCSV(const string);
void ReportStaff(string,const string);
void ReportManager(string, const string);

bool SortingByOwner(const vector<string>& a, const vector<string>& b) {
    return a[0] < b[0];
}

void SortItemsInLine(vector<string>& lineData) 
{
    vector<pair<string, string>> items;
    for (size_t i = 1; i < lineData.size(); i += 2) {
        items.push_back({lineData[i], lineData[i+1]});
    }
    sort(items.begin(), items.end());
    lineData.clear();
    lineData.push_back(""); // Placeholder for owner
    for (const auto& item : items) {
        lineData.push_back(item.second); // Push item name first
        lineData.push_back(item.first);  // Push item ID after
    }
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

void ReportCSV(const string filename) 
{
    cout << "Customer List: " << endl << endl;

    ifstream file(filename);

    vector<vector<string>> lines;
    string line;
    while (getline(file, line)) 
    {
        istringstream iss(line);
        vector<string> lineData;
        string token;
        while (getline(iss, token, ',')) 
        {
            lineData.push_back(token);
        }
        lines.push_back(lineData);
    }

    sort(lines.begin(), lines.end(), SortingByOwner); // Sort lines by owner

    for (const auto& lineData : lines) {
        cout << "Owner: " << lineData[0] << endl; 
        cout << "ID    | Name" << endl;
        cout << "--------------------" << endl;
        vector<string> mutableLineData = lineData; // Make a mutable copy
        SortItemsInLine(mutableLineData);
        for (size_t i = 1; i < mutableLineData.size(); i += 2) { 
            cout << mutableLineData[i+1] << " | " << mutableLineData[i] << endl;
        }
        cout << endl;
    }
    cout << "====================" << endl;
    cout << "Press Any Key and Enter to exit" << endl;

    string exit_choice;
    cin >> exit_choice;

    file.close();
}