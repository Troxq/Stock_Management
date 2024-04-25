// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void ReportCSV(const string);

// bool SortingByID(const vector<string>& a, const vector<string>& b) {
//     return a[0] < b[0]; 
// }

// void ReportMainMenu()
// {
//     system("clear");

//     string container_id_report;
//     cout << "Please Select Container ID : ";
//     cin >> container_id_report;
//     string prefix = "Database/container_";
//     string suffix = ".csv";

//     string fullfilename = prefix + container_id_report + suffix;

//     ReportCSV(fullfilename);
// }

// void ReportCSV(const string filename) 
// {
//     ifstream filedata("userdatabase.csv");

//     string dataline;
//     vector<vector<string>> users;

//     while(getline(filedata, dataline))
//     {
//         istringstream ss(dataline);
//         string token1, username, password, role, id;
//         vector<string> user;

//         while(getline(ss, token1, ','))
//         {
//             user.push_back(token1);
//         }

//         users.push_back(user);
//     }

//     sort(users.begin(), users.end(), [](const vector<string> &a, const vector<string> &b)
//     {
//         return a[2] == "Manager" && b[2] != "Manager";
//     });

//     filedata.close();

//     system("clear");
//     ifstream file(filename);

//     vector<vector<string>> items;
//     string line;
//     while (getline(file, line)) 
//     {
//         istringstream iss(line);
//         vector<string> itemData;
//         string token;
//         while (getline(iss, token, ',')) 
//         {
//             itemData.push_back(token);
//         }
//         items.push_back(itemData);
//     }

//     sort(items.begin(), items.end(), SortingByID); // Sort items by ID

//     for (const auto& item : items) {
//         cout << "Owner: " << item[0] << endl; 
//         for (size_t i = 1; i < item.size(); i += 2) { 
//             cout << "  Item: " << item[i+1] << " (ID: " << item[i] << ")" << endl;
//         }
//         cout << endl;
//     }
//     cout << "=========================" << endl;
//     cout << "Press Any Key and Enter to exit" << endl;
    

//     string exit_choice;
//     cin >> exit_choice;

//     file.close();
// }
