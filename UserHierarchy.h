#include <iostream>
#include <string>
#include "container.h"
#include <unistd.h>

using namespace std;

class Role
{
public:
    virtual void performTask() = 0;
    virtual void showNameandRole() = 0;
    virtual string get_role() = 0;
    virtual void mainMenu() = 0;
};

class Headquarter : public Role
{
public:
    string username, role;
    void performTask()
    {
        cout << "Performing a Headquarter task" << endl;
    }
    Headquarter(string username, string role)
    {
        cout << "Constructor for Headquarter!!!" << endl;
        this->username = username;
        this->role = role;
    }
    void showNameandRole()
    {
        cout << "NAME : " << this->username << " ROLE : "<< this->role << endl;
    }
    string get_role()
    {
        return this->role;
    }
    void mainMenu()
    {
        int choice = 0;
        while (1)
        {
            system("clear");
            cout << "1 Create user" << endl;
            cout << "2 Send order to manager" << endl;
            cout << "3 Order status" << endl;
            cout << "4 Report" << endl;
            cout << "0 exit" << endl;
            cout << "input : ";
            cin >> choice;
            if (choice == 1)
            {
                // createUser();

            }
            else if (choice == 2)
            {
                // sendOrder();
            }
            else if (choice == 3)
            {
                // orderStatus();
            }
            else if (choice == 4)
            {
                // report();
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "Please input 1 - 4" << endl;
                sleep(1);
            }
        }
    }
};
class Manager : public Headquarter
{
public:
    string username, role;
    void performTask() 
    {
        cout << "Performing a manager task" << endl;
    }
    Manager(string username, string role):Headquarter(username,role)
    {
        cout << "Constructor for Manager!!!" << endl;
        this->username = username;
        this->role = role;
    }
    void showNameandRole()
    {
        cout << "NAME : " << this->username << " ROLE : "<< this->role << endl;
    }
    void mainMenu()
    {
        int choice = 0;
        while (1)
        {
            system("clear");
            cout << "1 Send order to staff" << endl;
            cout << "2 Order status" << endl;
            cout << "3 Report" << endl;
            cout << "0 exit" << endl;
            cout << "input : ";
            cin >> choice;
            if (choice == 1)
            {
                // sendOrder();
            }
            else if (choice == 2)
            {
                // orderStatus();
            }
            else if (choice == 3)
            {
                // report();
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "Please input 1 - 3" << endl;
                sleep(1);
            }
        }
    }
};

class Staff : public Manager
{
public:
    string username, role;
    void performTask()
    {
        cout << "Performing a staff task" << endl;
    }
    Staff(string username, string role):Manager(username,role)
    {
        cout << "Constructor for Staff!!!" << endl;
        this->username = username;
        this->role = role;
    }
    void showNameandRole()
    {
        cout << "NAME : " << this->username << " ROLE : "<< this->role << endl;
    }


    void mainMenu()
    {
        int choice = 0;
        while (1)
        {
            system("clear");
            cout << "1 Input product" << endl;
            cout << "2 Export product" << endl;
            cout << "3 transfer product" << endl;
            cout << "4 Order status" << endl;
            cout << "0 exit" << endl;
            cout << "input : ";
            cin >> choice;
            if (choice == 1)
            {
                // input(); get container id to add to it

            }
            else if (choice == 2)
            {
                // export();
            }
            else if (choice == 3)
            {
                // transfer();
            }
            else if (choice == 4)
            {
                // orderStatus();
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "Please input 1 - 4" << endl;
                sleep(1);
            }
        }
    }
};

