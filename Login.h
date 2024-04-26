#include "UserHierarchy.h"
#include "Log.h"

void login(Role*&);
void MainPage(string);


void login(Role *&Role)
{
    string username, password, role;

    int role_choice;

    while(true)
    {
        cout << "Enter Your Username : "; 
        cin >> username;

        cout << "Enter Your Password : "; 
        cin >> password;

        if(usernamePasswordCheck(username,password,"userdatabase.csv"))
        {
            break;
        }
        else
        {
            cout << "No Match Username and Password" << endl;
        }
    }    

    while(true)
    {
        cout << "Choose Your Role (1. Headquarter, 2. Manager, 3. Staff) : ";
        cin >> role_choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10,'\n');
            continue;
        }

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

    int id;

    if((returnID(username,password,role,"userdatabase.csv")) != -1)
    {
        id = returnID(username,password,role,"userdatabase.csv");
    }

    if(role == "Headquarter")
    {
        Role = new Headquarter(username,role,id);
    }
    else if (role == "Manager")
    {
        Role = new Manager(username,role,id);
    }
    else if (role == "Staff")
    {
        Role = new Staff(username,role,id);
    }

    ifstream file("userdatabase.csv"); // Read userdatabase file

    string line;

    string datausername, datapassword, datarole, dataid; // To store a username & password from file

    while(getline(file, line))
    {
        split(line, ',', datausername, datapassword, datarole, dataid);
        if(datausername == username && datapassword == password && datarole == role)
        {
            login(username, role);
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