#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void split(string &, char, string &, string &, string &, string &); // Function to split username and password

bool usernameCheck(string &, string &); // Check if username exists

bool roleCheck(string &, string &, string);

int returnID(string &, string &, string &, string);

//HQ FUNCTION
void createUser();

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
        cin >> role_choice;

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
    } while (role_choice != 1 && role_choice != 2);

    cout << "Enter Container ID : ";
    cin >> id;

    ofstream file("userdatabase.csv", ios::app);

    file << username << "," << password << "," << role << "," << id << endl;

    file.close();

    cout << ">>>>>> Create User Successfully <<<<<<<" << endl;
}