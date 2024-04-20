#include <iostream>
#include <string>
#include "container.h"
#include <unistd.h>
#include "UserSystem.h"
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
    int id;
    void performTask()
    {
        cout << "Performing a Headquarter task" << endl;
    }
    Headquarter(string username, string role, int id)
    {
        cout << "Constructor for Headquarter!!!" << endl;
        this->username = username;
        this->role = role;
        this->id = id;
    }
    void showNameandRole()
    {
        cout << "HQ NAME : " << this->username << " ROLE : "<< this->role <<endl;
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
            showNameandRole();
            cout << "1 Create user" << endl;
            cout << "2 Send order to manager" << endl;
            cout << "3 Order status" << endl;
            cout << "4 Report" << endl;
            cout << "0 exit" << endl;
            cout << "input : ";
            cin >> choice;
            if (choice == 1)
            {
                system("clear");
                createUser();
            }
            else if (choice == 2)
            {
                // sendOrder();
            }
            else if (choice == 3)
            {
                // oderStatus();
            }
            else if (choice == 4)
            {
                // report();
            }
            else if (choice == 0)
            {
                system("clear");
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
    int id;
    void performTask() 
    {
        cout << "Performing a manager task" << endl;
    }
    Manager(string username, string role, int id):Headquarter(username,role,id)
    {
        cout << "Constructor for Manager!!!" << endl;
        this->username = username;
        this->role = role;
        this->id = id;
    }
    void showNameandRole()
    {
        cout << "MANAGER NAME : " << this->username << " ROLE : "<< this->role << " CONTAINER ID : " << this->id << endl;
    }
    void mainMenu()
    {
        int choice = 0;
        while (1)
        {
            system("clear");
            showNameandRole();
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
                system("clear");
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
    int id;
    void performTask()
    {
        cout << "Performing a staff task" << endl;
    }
    Staff(string username, string role, int id):Manager(username,role,id)
    {
        cout << "Constructor for Staff!!!" << endl;
        this->username = username;
        this->role = role;
        this->id = id;
    }
    void showNameandRole()
    {
        cout << "Staff NAME : " << this->username << " ROLE : "<< this->role << " CONTAINER ID : " << this->id << endl;
    }
    void mainMenu()
    {
        int choice = 0;
        while (1)
        {
            system("clear");
            showNameandRole();
            cout << "1 Input product" << endl;
            cout << "2 Export product" << endl;
            cout << "3 transfer product" << endl;
            cout << "4 Order status" << endl;
            cout << "0 exit" << endl;
            cout << "input : ";
            cin >> choice;
            if (choice == 1)
            {
                // input();
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
                system("clear");
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

