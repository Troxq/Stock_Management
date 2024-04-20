#include "UserHierarchy.h"

void login(Role*&);
void MainPage(string);


void login(Role *&Role)
{
    cout << "Login System" << endl;

    string username, password, role;

    int role_choice;

    cout << "Enter Your Username : "; 
    cin >> username;

    cout << "Enter Your Password : "; 
    cin >> password;

    while(true)
    {
        cout << "Choose Your Role (1. Headquarter, 2. Manager, 3. Staff) : ";
        cin >> role_choice;

        if(role_choice == 1)
        {
            role = "Headquarter";
        }
        else if(role_choice == 2)
        {
            role = "Manager";
        }
        else 
        {
            role = "Staff";
        }

        if(roleCheck(role, username, "userdatabase.csv"))
        {
            cout << "Welcome To The System!" << endl;
            break;
        }
        else
        {
            cout << "You are not in this role." << endl;
        }
    }

    if(role == "Headquarter")
    {
        Role = new Headquarter(username,role);
    }
    else if (role == "Manager")
    {
        Role = new Manager(username,role);
    }
    else if (role == "Staff")
    {
        Role = new Staff(username,role);
    }

    ifstream file("userdatabase.csv"); // Read userdatabase file

    string line;

    string datausername, datapassword, datarole; // To store a username & password from file

    while(getline(file, line))
    {
        split(line, ',', datausername, datapassword, datarole);
        if(datausername == username && datapassword == password && datarole == role)
        {
            cout << "Login Successfully" << endl;
            break;
        }
    }
}

void MainPage(string role)
{
    if(role == "Headquarter")
    {
        cout << "Hi I'm Headquarter!!" << endl;
    }
    while(true)
    {
        system("clear");
        cout << "This is a Main Page Yeah !!" << endl;
    }
}