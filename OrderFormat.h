// #include <string>
// #include <iostream>
// #include "NODE.h"
#include <unistd.h>
#include "OrderFormatHEADLL.h"
// #include "OrderFormatLL.h"
using namespace std;
// class 

int checkError(string nameP)
{
    if (nameP.size() > 30)
        return 1;
    return 0;
}


//snedOrderHQ

class sendOrderFormatHQ : public LinkedList
{
private:
    //string name;
    int numberContainer = 0;
    int itemAmount = 0;
    int duty = 0;

    // LinkedList allItems("item", 0);
    // struct item
    // {
    //     string productName;
    //     int productAmount;
        
    // }item[1000];

public:
    sendOrderFormatHQ(string, int = 0, int = 0);
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

sendOrderFormatHQ::sendOrderFormatHQ(string name, int numContainer, int d) : LinkedList(name, 0, "Pending", numContainer, d)
{
    numberContainer = numContainer;
    duty = d;
}

void sendOrderFormatHQ::mainMenu()
{
    int choice = 0;
    while (1)
    {
        // displayAll();
        cout << "1 Add product" << endl;
        cout << "2 Remove product" << endl;
        cout << "3 Check product" << endl;
        cout << "4 confirm" << endl;
        cout << "0 Cancle" << endl;
        cout << "input : ";
        cin >> choice;
        if (choice == 1)
        {
            addProduct();
        }
        else if (choice == 2)
        {
            removeProduct();
        }
        else if (choice == 3)
        {
            checkProduct();
        }
        else if (choice == 4)
        {
            confirm();
            break;
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

void sendOrderFormatHQ::addProduct()
{
    string nameP;
    int containerNum;
    int amount;
    while (1)
    {
        cout << "Add product name : ";
        cin >> nameP;
        if (checkError(nameP) == 0)
        {
            break;
        }
        else
        {
            cout << "Error try again" << endl;
        }
    }
    cout << "Add amount : ";
    cin >> amount;
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
    orderStatusFormatHQ(int);
};

orderStatusFormatHQ::orderStatusFormatHQ(int numC) : headLinkList()
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