#include <iostream>
#include <string>
#include "container.h"
// #include "OrderFormatHEADLL.h"
#include <unistd.h>
#include "OrderFormat.h"
// #include "OrderFormatManager.h"

#include "UserSystem.h"
#include "Logmain.cpp"
// #include "Report.h"
// #include "FunctionContainer.h"
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
        // cout << "Constructor for Headquarter!!!" << endl;
        this->username = username;
        this->role = role;
        this->id = id;
    }
    void showNameandRole()
    {
        cout << "===============================" << endl;
        cout << "|| NAME : " << this->username 
             << "\n|| ROLE : "<< this->role <<endl;
        cout << "===============================" << endl;
    }
    string get_role()
    {
        return this->role;
    }
    void sendOrder()
    {
        while (1)
        {
            int choice;
            try
            {
                system("clear");
                cout << "1 Import products" << endl;
                cout << "2 Export products" << endl;
                cout << "3 Transfer products" << endl;
                cout << "0 Exit" << endl;
                cout << "Input : ";
                cin >> choice;
                if (cin.fail())
                {
                    throw 1;
                }

                if (choice == 1)
                {
                    string name;
                    int containerNum;
                    while (1)
                    {
                        cout << "input name of owner product : ";
                        cin >> name;
                        cin.ignore(50, '\n');
                        if (checkInputStr(name) == 1)
                            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
                        else if (checkInputStr(name) == 2)
                            cout << "Error: Invalid input. Please don't use special character" << endl;       
                        else
                            break;
                    }
                    while (1)
                    {
                        try{
                            cout << "Number of container : "; 
                            cin >> containerNum;
                            if (cin.fail())
                                throw 1;
                            break;
                        }
                        catch (...){
                            cout << "Error: try again" << endl;
                            cin.clear();
                            cin.ignore(50, '\n');
                        }
                    }
                    sendOrderFormatHQ order(name, containerNum, 1);
                    order.mainMenu();
                    send_order(this->username, this->role, containerNum, 1);
                }
                else if (choice == 2)
                {
                    string name;
                    int containerNum;
                    while (1)
                    {
                        cout << "input name of owner product : ";
                        cin >> name;
                        cin.ignore(50, '\n');
                        if (checkInputStr(name) == 1)
                            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
                        else if (checkInputStr(name) == 2)
                            cout << "Error: Invalid input. Please don't use special character" << endl;       
                        else
                            break;
                    }
                    while (1)
                    {
                        try{
                            cout << "Number of container : "; 
                            cin >> containerNum;
                            if (cin.fail())
                                throw 1;
                            break;
                        }
                        catch (...){
                            cout << "Error: try again" << endl;
                            cin.clear();
                            cin.ignore(50, '\n');
                        }
                    }
                    sendOrderFormatHQ order(name, containerNum, 2);
                    order.mainMenu();
                    send_order(this->username, this->role, containerNum, 2);
                }
                else if (choice == 3)
                {
                    string name;
                    int containerNum;
                    int sendId;
                    while (1)
                    {
                        cout << "input name of owner product : ";
                        cin >> name;
                        cin.ignore(50, '\n');
                        if (checkInputStr(name) == 1)
                            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
                        else if (checkInputStr(name) == 2)
                            cout << "Error: Invalid input. Please don't use special character" << endl;       
                        else
                            break;
                    }
                    while (1)
                    {
                        try{
                            cout << "Number of container : "; 
                            cin >> containerNum;
                            if (cin.fail())
                                throw 1;
                            
                            cout << "Send to container id : ";
                            cin >> sendId;
                            if (cin.fail())
                                throw 1;

                            break;
                        }
                        catch (...){
                            cout << "Error: try again" << endl;
                            cin.clear();
                            cin.ignore(50, '\n');
                        }
                    }
                    sendOrderFormatHQ order(name, containerNum, 3, sendId);
                    order.mainMenu();
                    send_order(this->username, this->role, containerNum, 2);
                }
                else if (choice == 0)
                {
                    break;
                }
                else
                {
                    cout << "Error: Please input 0 - 3" << endl;
                    sleep(1);
                }
            }
            catch (...)
            {
                cout << "Error: try again" << endl;
                sleep(1);
                cin.clear();
                cin.ignore(50, '\n');
            }
        }
    }
    void orderStatus()
    {
        string a; // test
        orderStatusFormatHQ status(id, username, role);
        // cout << "id : " << id << endl;
        // cin >> a;
        status.load_data_HQ("OrderStatusHQDatabase.csv");
        status.displayOrderStatusHQ();
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
            cout << "5 Log" << endl;
            cout << "0 Exit" << endl;
            cout << "input : ";
            cin >> choice;
            if (choice == 1)
            {
                system("clear");
                createUser();
            }
            else if (choice == 2)
            {
                sendOrder();
            }
            else if (choice == 3)
            {
                orderStatus();
            }
            else if (choice == 4)
            {
                // ReportMainMenu();
            }
            else if (choice == 5)
            {
                Logmenu();
            }
            else if (choice == 0)
            {
                system("clear");
                break;
            }
            else
            {
                cout << "Error: Please input 0 - 5" << endl;
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
        // cout << "Constructor for Manager!!!" << endl;
        this->username = username;
        this->role = role;
        this->id = id;
    }
    void showNameandRole()
    {
        cout << "===============================" << endl;
        cout << "|| NAME : " << this->username 
             << "\n|| ROLE : "<< this->role <<endl;
        cout << "===============================" << endl;
    }
    void sendOrder()
    {
        orderFormatManager b(id, this->username, this->role);
        b.load_data("OrderManagerDatabase.csv");
        b.displaySendOrderManager();

    }
    void orderStatus()
    {
        orderFormatManager b(id, this->username, this->role);
        b.load_data("OrderStatusManagerDatabase.csv");
        b.displayOrderStatusManager();
    }
    void mainMenu()
    {
        int choice = 0;
        while (1)
        {
            int a;
            system("clear");
            showNameandRole();
            cout << "1 Send order to staff" << endl;
            cout << "2 Order status" << endl;
            cout << "3 Report" << endl;
            cout << "0 Exit" << endl;
            cout << "Input : ";
            cin >> choice;
            if (choice == 1)
            {
                sendOrder();
            }
            else if (choice == 2)
            {
                orderStatus();
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
                cout << "Error: Please input 0 - 3" << endl;
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
        // cout << "Constructor for Staff!!!" << endl;
        this->username = username;
        this->role = role;
        this->id = id;
    }
    void showNameandRole()
    {
        cout << "===============================" << endl;
        cout << "|| NAME : " << this->username 
             << "\n|| ROLE : "<< this->role <<endl;
        cout << "===============================" << endl;
    }
    void orderStatus()
    {
        orderFormatStaff order(id);
        order.load_data("OrderStaffDatabase.csv");
        order.displayOrderStatusStaff();
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
            cout << "3 Transfer product" << endl;
            cout << "4 Send order to manager" << endl;
            cout << "0 Exit" << endl;
            cout << "Input : ";
            cin >> choice;
            if (choice == 1)
            {
                inputproduct(this->id);
            }
            else if (choice == 2)
            {
                exportproduct(this->id);
            }
            else if (choice == 3)
            {
                transferproduct(this->id);
            }
            else if (choice == 4)
            {
                orderStatus();
            }
            else if (choice == 0)
            {
                system("clear");
                break;
            }
            else
            {
                cout << "Error: Please input 0 - 4" << endl;
                sleep(1);
            }
        }
    }
};

