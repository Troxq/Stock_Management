#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareItemsById(const vector<string>& a, const vector<string>& b) {
    return a[0] < b[0]; // Assuming ID is at index 0 of each item vector
}

void ReportCSV() 
{
    system("clear");
    ifstream file("Database/container_1.csv");

    vector<vector<string>> items;
    string line;
    while (getline(file, line)) 
    {
        istringstream iss(line);
        vector<string> itemData;
        string token;
        while (getline(iss, token, ',')) 
        {
            itemData.push_back(token);
        }
        items.push_back(itemData);
    }

    sort(items.begin(), items.end(), compareItemsById); // Sort items by ID

    for (const auto& item : items) {
        cout << "Owner: " << item[0] << endl; // Assuming owner name is at index 0
        for (size_t i = 1; i < item.size(); i += 2) { // Assuming items are in pairs (ID, Name)
            cout << "  Item: " << item[i+1] << " (ID: " << item[i] << ")" << endl;
        }
        cout << endl;
    }
    cout << "=========================" << endl;
    cout << "Press Any Key and Enter to exit" << endl;
    

    string exit_choice;
    cin >> exit_choice;

    file.close();
}
