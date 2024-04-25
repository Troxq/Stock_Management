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
    void removeProduct();
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
        cout << "Error: Please don't input same customer name" << endl;
        sleep(1);
        return;
    }
    while (1)
    {
        // displayAll();
        try
        {
            if (choice != 3)
                system("clear");
            cout << "1 Add product" << endl;
            cout << "2 Remove product" << endl;
            cout << "3 Check product" << endl;
            cout << "4 confirm" << endl;
            cout << "0 Cancle" << endl;
            cout << "input : ";
            cin >> choice;
            if (cin.fail())
                throw 1;
            if (choice == 1)
            {
                system("clear");
                addProduct();
            }
            else if (choice == 2)
            {
                system("clear");
                removeProduct();
            }
            else if (choice == 3)
            {
                system("clear");
                checkProduct();
            }
            else if (choice == 4)
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
                cout << "Error: Invalid input. Please input 0 - 4" << endl; 
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
    int amount;
    while (1)
    {
        try{
            cout << "Add product name : ";
            cin.clear();
            cin.ignore(50, '\n');
            cin >> nameP;
            checkInputStr(nameP);
            break;
        }
        catch (const char *str)
        {
            cin.clear();
            cin.ignore(50, '\n');
            cout << str << endl;
        }
    }
    while (1)
    {
        try{
            cout << "Add amount : ";
            cin >> amount;
            if (cin.fail())
                throw 1;
            break;
        }
        catch(...)
        {
            cout << "Error: Invalid input. Please enter a valid option." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(50, '\n'); // Discard invalid input
            sleep(1);
        }

    }
    add_NODE(nameP, amount);
    itemAmount += 1;
}

void sendOrderFormatHQ::removeProduct()
{
    string nameP;
    cout << "Remove product name : ";
    cin >> nameP;
    delete_NODE_Got(nameP);
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