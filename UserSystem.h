#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Log.h"
#include "FunctionContainer.h"

using namespace std;

void split(string &, char, string &, string &, string &, string &); // Function to split username and password

bool usernameCheck(string &, string &); // Check if username exists

bool usernamePasswordCheck(string &, string &, string);

bool roleCheck(string &, string &, string);

int returnID(string &, string &, string &, string);

void initCSV();

void initDatabase();

void initCSV()
{
    string filename = "Database/HQ.csv";
    ifstream fileCheck(filename);
    if (fileCheck) 
    {
        // cout << "Initailize HQ.csv ........." << endl;
        // sleep(1);
        return;
    }

    ofstream file(filename, ios::out | ios::app);
    if (file.is_open()) 
    {
        file << "id,00000,\n";
        file.close();
    } 
    else 
    {
        cerr << "Unable to open file: " << filename << endl;
    } 
}

void initOrderCSV() 
{
    vector<string> filenames = {"OrderManagerDatabase.csv", 
                                "OrderStaffDatabase.csv", 
                                "OrderStatusHQDatabase.csv", 
                                "OrderStatusManagerDatabase.csv"};

    for (const string& filename : filenames) 
    {
        ifstream fileCheck(filename);
        if (fileCheck) 
        {
            // cout << "Initialize " << filename << " .........." << endl;
            // sleep(1);
            continue;
        }

        ofstream file(filename, ios::out | ios::app);
        if (file.is_open()) 
        {
            file.close();
        } 
        else 
        {
            cerr << "Unable to open file: " << filename << endl;
        }
    }
}

void initDatabase()
{
    
    string filename = "userdatabase.csv";
    ifstream fileCheck(filename);
    if (fileCheck) 
    {
        // cout << "Initailize userdatabase.csv ........." << endl;
        // sleep(1);
        return;
    }

    ofstream file(filename, ios::out | ios::app);
    if (file.is_open()) 
    {
        file << "Admin,Admin,Headquarter,0\n";
        file.close();
    } 
    else 
    {
        cerr << "Unable to open file: " << filename << endl;
    } 
}

//HQ FUNCTION
void createUser();

bool ManagerCheck(const string &, int);

bool ManagerCheck(const string& filename, int id) 
{
    ifstream file(filename);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password, role;
        int currentId;

        if (getline(ss, username, ',') &&
            getline(ss, password, ',') &&
            getline(ss, role, ',') &&
            (ss >> currentId)) {

            if (currentId == id && role == "Manager") {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

void split(string &line, char separate, string &username, string &password, string &role, string &id)
{
    int pos1 = line.find(separate); 
    int pos2 = line.find(separate, pos1 + 1); 
    int pos3 = line.find(separate, pos2 + 1); 

    if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos)
    {
        username = line.substr(0, pos1);
        password = line.substr(pos1 + 1, pos2 - pos1 - 1);
        role = line.substr(pos2 + 1, pos3 - pos2 - 1);
        id = line.substr(pos3 + 1);
    }
}


bool usernameCheck(string &username, string filename)
{
    ifstream file(filename); // open userdatabase file
    
    string line;

    while(getline(file, line))
    {
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        if(datausername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool usernamePasswordCheck(string& username, string& password, string filename)
{
    ifstream file(filename); // open userdatabase file
    
    string line;

    while (getline(file, line))
    {
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        if (datausername == username && datapassword == password)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool roleCheck(string &role, string &username, string filename)
{
    ifstream file(filename); // open userdatabase file
    
    string line;

    while(getline(file, line))
    {
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        if(datausername == username && datarole == role)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int returnID(string &username, string &password, string &role, string filename)
{
    ifstream file(filename); // open userdatabase file

    string line;

    while (getline(file, line))
    {
        string datausername, datapassword, datarole, dataid;
        split(line, ',', datausername, datapassword, datarole, dataid);
        if (datausername == username && datapassword == password && datarole == role)
        {
            file.close();
            return atoi(dataid.c_str());
        }
    }

    file.close();
    return -1;
}

//HQ FUNCTION

void createUser()
{
    cout << ">>>>>> Create User System <<<<<<" << endl;

    string username, password, role;
    int id;

    while (true)
    {
        cout << "Enter Username: ";
        cin >> username;

        if (usernameCheck(username, "userdatabase.csv")) // Check Username
        {
            cout << "Username already exists !!" << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Enter Password: ";
    cin >> password;

    int role_choice;

    do
    {
        cout << "Select Role (1. Staff, 2. Manager): ";
        
        if(cin>>role_choice)
        {    
            switch (role_choice)
            {
            case 1:
                role = "Staff";
                break;
            case 2:
                role = "Manager";
                break;
            default:
                cout << "Invalid role choice. Please select again." << endl;
                break;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input. Please enter an integer (1|2).\n";
            continue;
        }
    } while (role_choice != 1 && role_choice != 2);

    while (true) {
        cout << "Enter Container ID : ";
        cin >> id;
        if (!cin.fail()) {
            break;
        } else {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "Invalid input. Please enter an integer (ID).\n";
        }
    }

    if(role == "Staff" && !ManagerCheck("userdatabase.csv",id))
    {
        cout << "There is no Manager with this ID yet !!!" << endl;
        sleep(2);
        return;
    }

    if(role == "Manager" && ManagerCheck("userdatabase.csv",id))
    {
        cout << "There is already a Manager with this ID !!!" << endl;
        sleep(2);
        return;
    }

    ofstream file("userdatabase.csv", ios::app);

    file << username << "," << password << "," << role << "," << id << endl;

    regis(username, role);

    file.close(); // Ended Create user process

    if(role == "Manager") //Create Container for new Manager
    {    
        string create_container_id = to_string(id);

        HQ * HQptr = new HQ("W",0);

        load_file_into_HQptr(HQptr);

        HQptr->add_container(create_container_id,0);

        save_file(HQptr);

        delete(HQptr);
    }

    cout << ">>>>>> Create User Successfully <<<<<<<" << endl;
}