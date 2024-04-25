// #include <string>
// #include <iostream>
// #include "NODE.h"
#include <unistd.h>
#include "OrderFormatHEADLL.h"
#include "checkerror.h"
// #include "OrderFormatLL.h"
using namespace std;
// class 


//snedOrderHQ

class sendOrderFormatHQ : public LinkedList
{
private:
    //string name;
    int numberContainer = 0;
    int itemAmount = 0;
    int duty = 0;
    int sendIdContainer = 0;

    // LinkedList allItems("item", 0);
    // struct item
    // {
    //     string productName;
    //     int productAmount;
        
    // }item[1000];

public:
    sendOrderFormatHQ(string, int = 0, int = 0, int = 0);
    void mainMenu();
    void addProduct();
    void addProductExportTransfer();
    void removeProduct();
    void removeProductExportTransfer();
    void checkProduct();
    void confirm();

    // 1 cig 20
    // 2 car 10
    // 3 book 30

    // 1 add product
    // 2 remove product
    // 3 check product
    // 4 confirm
    // 0 cancle
    
};

sendOrderFormatHQ::sendOrderFormatHQ(string name, int numContainer, int d, int sendId) : LinkedList(name, 0, "Pending", numContainer, d, sendId)
{
    numberContainer = numContainer;
    duty = d;
    sendIdContainer = sendId;
}

void sendOrderFormatHQ::mainMenu()
{
    int choice = 0;
    if (load_data_for_check("OrderStatusHQDatabase.csv", this->return_name()) == 1)
    {
        return;
    }
    while (1)
    {
        // displayAll();
        try
        {
            system("clear");
            checkProduct();
            cout << "1 Add product" << endl;
            cout << "2 Remove product" << endl;
            cout << "3 confirm" << endl;
            cout << "0 Cancle" << endl;
            // cout << "3 Check product" << endl;
            cout << "input : ";
            cin >> choice;
            if (cin.fail())
                throw 1;
            if (choice == 1)
            {
                system("clear");
                checkProduct();
                if (duty == 1)
                    addProduct();
                else
                {
                    addProductExportTransfer();
                }
            }
            else if (choice == 2)
            {
                system("clear");
                checkProduct();
                if (duty == 1)
                    removeProduct();
                else
                {
                    removeProductExportTransfer();
                }
            }
            else if (choice == 3)
            {
                if (itemAmount <= 0)
                {
                    cout << "Error: Please add at least one product" << endl;
                    sleep(1);
                }
                else
                {
                    confirm();
                    break;
                }
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                cout << "Error: Invalid input. Please input 0 - 3" << endl; 
                sleep(1);
            }
        }
        catch(...)
        {
            cout << "Error: Invalid input. Please enter a valid option." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(50, '\n'); // Discard invalid input
            sleep(1);
        }
    }
}

void sendOrderFormatHQ::addProduct()
{
    string nameP;
    int containerNum;
    int amount = 0;
    while (1)
    {
        cout << "Add product name : ";
        cin >> nameP;
        cin.ignore(50, '\n');
        if (checkInputStr(nameP) == 1)
            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
        else if (checkInputStr(nameP) == 2)
            cout << "Error: Invalid input. Please don't use special character" << endl;       
        else
            break;
    }
    while (1)
    {
        try{
            cout << "Add amount : ";
            cin >> amount;
            if (cin.fail() || amount <= 0)
                throw 1;
            break;
        }
        catch(...)
        {
            cout << "Error: Invalid input. Please input number and more than zero." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(50, '\n'); // Discard invalid input
            sleep(1);
        }

    }
    add_NODE(nameP, amount);
    itemAmount += 1;
}

void sendOrderFormatHQ::addProductExportTransfer()
{
    string idP;
    int containerNum;
    int amount = 0;
    while (1)
    {
        cout << "Add product id : ";
        cin >> idP;
        cin.ignore(50, '\n');
        if (checkInputNum(idP) == 1)
            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
        else if (checkInputNum(idP) == 2)
            cout << "Error: Invalid input. Please input only number" << endl; 
        else if (check_item_id_exist(idP) == 0)
            cout << "Error: Don't have this ID in container" << endl; 
        else
            break;
    }
    // while (1)
    // {
    //     try{
    //         cout << "Add amount : ";
    //         cin >> amount;
    //         if (cin.fail())
    //             throw 1;
    //         break;
    //     }
    //     catch(...)
    //     {
    //         cout << "Error: Invalid input. Please enter a valid option." << endl;
    //         cin.clear(); // Clear the error flag
    //         cin.ignore(50, '\n'); // Discard invalid input
    //         sleep(1);
    //     }

    // }
    add_NODE(idP, amount);
    itemAmount += 1;
}

void sendOrderFormatHQ::removeProduct()
{
    string nameP;
    while (1)
    {
        cout << "Remove product name : ";
        cin >> nameP;
        cin.ignore(50, '\n');
        if (checkInputStr(nameP) == 1)
            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
        else if (checkInputStr(nameP) == 2)
            cout << "Error: Invalid input. Please don't use special character" << endl;       
        else
            break;
    }
    delete_NODE_Got(nameP);
    itemAmount -= 1;
}

void sendOrderFormatHQ::removeProductExportTransfer()
{
    string idP;
    while (1)
    {
        cout << "Remove product id : ";
        cin >> idP;
        cin.ignore(50, '\n');
        if (checkInputNum(idP) == 1)
            cout << "Error: Invalid input. Please don't input more than 50 character" << endl;
        else if (checkInputNum(idP) == 2)
            cout << "Error: Invalid input. Please input only number" << endl;       
        else
            break;
    }
    delete_NODE_Got(idP);
    itemAmount -= 1;
}

void sendOrderFormatHQ::checkProduct()
{
    displayAll();
}

void sendOrderFormatHQ::confirm()
{
    save_data_HQ("OrderManagerDatabase.csv", 0);
    save_data_HQ("OrderStatusHQDatabase.csv", 0);
}


class orderStatusFormatHQ : public headLinkList
{
private:
    int numberContainer;

public:
    orderStatusFormatHQ(int, string, string);
};

orderStatusFormatHQ::orderStatusFormatHQ(int numC, string name, string role) : headLinkList(numC, name, role)
{
    numberContainer = numC;
}


// SendOrderManager



class orderFormatManager : public headLinkList
{
private:
    int numberContainer;

public:
    orderFormatManager(int, string, string);
    // display();
};

orderFormatManager::orderFormatManager(int numC, string name, string role) : headLinkList(numC, name, role)
{
    numberContainer = numC;
    cout << "--------------" << endl;
    cout << name << " " << role << endl;
    cout << "--------------" << endl;
}


class orderFormatStaff : public headLinkList
{
private:
    int numberContainer;

public:
    orderFormatStaff(int);
};

orderFormatStaff::orderFormatStaff(int numC) : headLinkList(numC)
{
    numberContainer = numC;
}