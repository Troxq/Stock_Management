#include <string>
#include <iostream>
#include <vector>
#include "OrderFormatLL.h"
#include "Log.h"

using namespace std;

class headLinkList
{
private:
    LinkedList *holLinkedList;
    int sizeNodeinLinkList;
    int id;
    string name;
    string role;

public:
    headLinkList(int = 0, string="", string="");
    void delete_LinkedList(string);
    void delete_LinkedList(string, string, int = 0);
    void delete_LinkedList(string, string, int, string, int);
    void delete_LinkedList(string, string, int, string, int, string, int);
    void add_LinkedList(LinkedList *&);
    void load_data(string);
    void load_data_other(string);
    void load_data_HQ(string);
    void return_name();
    void save_data_LinkList(string, int = 0);
    void displaySendOrderManager();
    void displayOrderStatusHQ();
    void displayOrderStatusManager();
    void displayOrderStatusStaff();

};


headLinkList::headLinkList(int idContainer, string name, string r)
{
    holLinkedList = NULL;
    sizeNodeinLinkList = 0;
    id = idContainer;
    name = name;
    role = r;

    cout << "--------------" << endl;
    cout << name << " " << role << endl;
    cout << "--------------" << endl;
}

void headLinkList::delete_LinkedList(string nameOwner)
{

    LinkedList *currentPtr, *previousPtr;
    currentPtr = holLinkedList;
    previousPtr = NULL;

    if (sizeNodeinLinkList > 0)
    {
        if (currentPtr->return_name() == nameOwner)
        {
            if (holLinkedList->move_next() != NULL)
            {
                holLinkedList = holLinkedList->move_next();
                holLinkedList->set_back_LinkList_ptr(NULL);
                cout << currentPtr->return_name() << " has been deleted" << endl;
            }
            else
            {
                holLinkedList = NULL;
            }
            free(currentPtr);
            sizeNodeinLinkList -= 1;
        }
        else
        {
            for (int len = sizeNodeinLinkList - 1; len > 0 && currentPtr->return_name() != nameOwner; len--)
            {
                // cout << "currentPtr : " << currentPtr->return_name() << "     |    nameOwner : " << nameOwner << endl;
                // cout << "eiei" << endl;
                previousPtr = currentPtr;
                currentPtr = currentPtr->move_next();
            }
            
            LinkedList *t = currentPtr;
            currentPtr = currentPtr->move_next();
            previousPtr->set_next_LinkList_ptr(currentPtr);
            if (currentPtr != NULL)
            {
                currentPtr->set_back_LinkList_ptr(previousPtr);
            }
            cout << t->return_name() << " has been deleted" << endl;
            delete t;
            sizeNodeinLinkList -= 1;
        }
    }
}

void headLinkList::delete_LinkedList(string nameOwner, string nameFile, int status)
{

    LinkedList *currentPtr, *previousPtr;
    currentPtr = holLinkedList;
    previousPtr = NULL;

    if (sizeNodeinLinkList > 0)
    {
        if (currentPtr->return_name() == nameOwner)
        {
            if (holLinkedList->move_next() != NULL)
            {
                holLinkedList = holLinkedList->move_next();
                holLinkedList->set_back_LinkList_ptr(NULL);
                cout << currentPtr->return_name() << " has been deleted" << endl;
            }
            else
            {
                holLinkedList = NULL;
            }
            currentPtr->save_data(nameFile, status);
            free(currentPtr);
            sizeNodeinLinkList -= 1;
        }
        else
        {
            for (int len = sizeNodeinLinkList - 1; len > 0 && currentPtr->return_name() != nameOwner; len--)
            {
                // cout << "currentPtr : " << currentPtr->return_name() << "     |    nameOwner : " << nameOwner << endl;
                // cout << "eiei" << endl;
                previousPtr = currentPtr;
                currentPtr = currentPtr->move_next();
            }
            
            LinkedList *t = currentPtr;
            currentPtr = currentPtr->move_next();
            previousPtr->set_next_LinkList_ptr(currentPtr);
            if (currentPtr != NULL)
            {
                currentPtr->set_back_LinkList_ptr(previousPtr);
            }
            t->save_data(nameFile, status);
            cout << t->return_name() << " has been deleted" << endl;
            delete t;
            sizeNodeinLinkList -= 1;
        }
    }
}

void headLinkList::delete_LinkedList(string nameOwner, string nameFile1, int status1, string nameFile2, int status2)
{

    LinkedList *currentPtr, *previousPtr;
    currentPtr = holLinkedList;
    previousPtr = NULL;

    if (sizeNodeinLinkList > 0)
    {
        if (currentPtr->return_name() == nameOwner)
        {
            if (holLinkedList->move_next() != NULL)
            {
                holLinkedList = holLinkedList->move_next();
                holLinkedList->set_back_LinkList_ptr(NULL);
                cout << currentPtr->return_name() << " has been deleted" << endl;
            }
            else
            {
                holLinkedList = NULL;
            }
            currentPtr->save_data(nameFile1, status1);
            currentPtr->save_data(nameFile2, status2);
            free(currentPtr);
            sizeNodeinLinkList -= 1;
        }
        else
        {
            for (int len = sizeNodeinLinkList - 1; len > 0 && currentPtr->return_name() != nameOwner; len--)
            {
                // cout << "currentPtr : " << currentPtr->return_name() << "     |    nameOwner : " << nameOwner << endl;
                // cout << "eiei" << endl;
                previousPtr = currentPtr;
                currentPtr = currentPtr->move_next();
            }
            
            LinkedList *t = currentPtr;
            currentPtr = currentPtr->move_next();
            previousPtr->set_next_LinkList_ptr(currentPtr);
            if (currentPtr != NULL)
            {
                currentPtr->set_back_LinkList_ptr(previousPtr);
            }
            
            t->save_data(nameFile1, status1);
            t->save_data(nameFile2, status2);
            cout << t->return_name() << " has been deleted" << endl;
            delete t;
            sizeNodeinLinkList -= 1;
        }
    }
}

void headLinkList::delete_LinkedList(string nameOwner, string nameFile1, int status1, string nameFile2, int status2, string nameFile3, int status3)
{

    LinkedList *currentPtr, *previousPtr;
    currentPtr = holLinkedList;
    previousPtr = NULL;

    if (sizeNodeinLinkList > 0)
    {
        if (currentPtr->return_name() == nameOwner)
        {
            if (holLinkedList->move_next() != NULL)
            {
                holLinkedList = holLinkedList->move_next();
                holLinkedList->set_back_LinkList_ptr(NULL);
                cout << currentPtr->return_name() << " has been deleted" << endl;
            }
            else
            {
                holLinkedList = NULL;
            }
            currentPtr->save_data(nameFile1, status1);
            currentPtr->save_data(nameFile2, status2);
            currentPtr->save_data(nameFile3, status3);
            free(currentPtr);
            sizeNodeinLinkList -= 1;
        }
        else
        {
            for (int len = sizeNodeinLinkList - 1; len > 0 && currentPtr->return_name() != nameOwner; len--)
            {
                // cout << "currentPtr : " << currentPtr->return_name() << "     |    nameOwner : " << nameOwner << endl;
                // cout << "eiei" << endl;
                previousPtr = currentPtr;
                currentPtr = currentPtr->move_next();
            }
            
            LinkedList *t = currentPtr;
            currentPtr = currentPtr->move_next();
            previousPtr->set_next_LinkList_ptr(currentPtr);
            if (currentPtr != NULL)
            {
                currentPtr->set_back_LinkList_ptr(previousPtr);
            }
            t->save_data(nameFile2, status2);
            t->save_data(nameFile3, status3);
            t->save_data(nameFile1, status1);
            cout << t->return_name() << " has been deleted" << endl;
            delete t;
            sizeNodeinLinkList -= 1;
        }
    }
}

void headLinkList::save_data_LinkList(string nameFile, int status)
{
    ofstream myfile(nameFile);
    LinkedList *t = holLinkedList;

    if (t == NULL)
        return ;
    if (myfile.is_open()) 
    {
        // Traverse to the last linked list
        while (t->move_next() != NULL)
        {
            t = t->move_next();
        }

        // Traverse backward through the linked lists
        while (t != NULL)
        {
            myfile << t->return_sendIdContainer() << "," << t->return_duty() << "," << t->return_idContainer() << "," << status << "," << t->return_name() << "," << t->return_size();
            NODE *y = t->return_node(); // Start from the first node
            
            // Traverse forward through the nodes
            for (int j = 0; j < t->return_size(); j++)
            {
                myfile << "," << y->return_name() << "," << y->return_amount();
                y = y->return_next_NODE();
            }
            myfile << endl;
            t = t->move_back();
        }
        // cout << "Data has been appended and saved in reverse order." << endl;
        myfile.close(); // Close the file inside the loop
    }
    else 
    {
        cout << "Unable to open file!" << endl;
    }
}



void headLinkList::add_LinkedList(LinkedList *&A){
    
    holLinkedList->insert(A);
    holLinkedList = A;

    sizeNodeinLinkList++;

}

void headLinkList::load_data(string namefile)
{
    // File pointer
    ifstream fin;

    // Open an existing file
    fin.open(namefile);

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int idContainer = stoi(row[2]);

        
        if (idContainer != this->id)
        {
            continue;
        }

        int sendId = stoi(row[0]);

        int duty = stoi(row[1]);

        int status = stoi(row[3]);
        string nameStatus;
        switch (status)
        {
            case 0 : nameStatus = "Pending"; break;
            case 1 : nameStatus = "Confirm"; break;
            case 2 : nameStatus = "Finish"; break;
            case 3 : nameStatus = "Deny"; break;
        }

        string nameLinklist = row[4];
        int size = stoi(row[5]);
        // int sizeLinkList = stoi(row[1]) / 2;

        // cout << "size = " << size << endl;
        // cout << "size \\ 2 = " << size / 2 << endl;
        // cin >> size;
        LinkedList *owner = new LinkedList(nameLinklist, 0, nameStatus, idContainer, duty, sendId);

        if (size > 0)
        {
            for (int i = row.size() - 1; i >= 6; i -= 2)
            {
                owner->add_NODE(row[i - 1], stoi(row[i]));
            }
        }
        // owner->displayAll();
        this->add_LinkedList(owner);
        // delete owner;
        // sizeNodeinLinkList += 1;
    }

    fin.close();
}

void headLinkList::load_data_other(string namefile)
{
    // File pointer
    ifstream fin;

    // Open an existing file
    fin.open(namefile);

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int idContainer = stoi(row[2]);

        
        if (idContainer == this->id)
        {
            continue;
        }

        int sendId = stoi(row[0]);

        int duty = stoi(row[1]);

        int status = stoi(row[3]);
        string nameStatus;
        switch (status)
        {
            case 0 : nameStatus = "Pending"; break;
            case 1 : nameStatus = "Confirm"; break;
            case 2 : nameStatus = "Finish"; break;
            case 3 : nameStatus = "Deny"; break;
        }

        string nameLinklist = row[4];
        int size = stoi(row[5]);
        // int sizeLinkList = stoi(row[1]) / 2;

        // cout << "size = " << size << endl;
        // cout << "size \\ 2 = " << size / 2 << endl;
        // cin >> size;
        LinkedList *owner = new LinkedList(nameLinklist, 0, nameStatus, idContainer, duty, sendId);

        if (size > 0)
        {
            for (int i = row.size() - 1; i >= 6; i -= 2)
            {
                owner->add_NODE(row[i - 1], stoi(row[i]));
            }
        }
        // owner->displayAll();
        this->add_LinkedList(owner);
        // delete owner;
        // sizeNodeinLinkList += 1;
    }

    fin.close();
}

void headLinkList::load_data_HQ(string namefile)
{
    // File pointer
    ifstream fin;

    // Open an existing file
    fin.open(namefile);

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        int sendId = stoi(row[0]);

        int idContainer = stoi(row[2]);

        int duty = stoi(row[1]);
    
        int status = stoi(row[3]);
        string nameStatus;
        switch (status)
        {
            case 0 : nameStatus = "Pending"; break;
            case 1 : nameStatus = "Confirm"; break;
            case 2 : nameStatus = "Finish"; break;
            case 3 : nameStatus = "Deny"; break;
        }
        string nameLinklist = row[4];
        int size = stoi(row[5]);
        // int sizeLinkList = stoi(row[1]) / 2;

        // cout << "size = " << size << endl;
        // cout << "size \\ 2 = " << size / 2 << endl;
        // cin >> size;
        LinkedList *owner = new LinkedList(nameLinklist, 0, nameStatus, idContainer, duty, sendId);

        if (size > 0)
        {
            for (int i = row.size() - 1; i >= 6; i -= 2)
            {
                owner->add_NODE(row[i - 1], stoi(row[i]));
            }
        }
        // owner->displayAll();
        this->add_LinkedList(owner);
        // sizeNodeinLinkList += 1;
    }

    fin.close();
}

void headLinkList::displayOrderStatusHQ()
{
    int len = 0;
    int choice;
    LinkedList *t;

    t = holLinkedList;
    while (1)
    {
        string confirm;
        if (t == NULL)
        {
            system("clear");
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "|                   Don't have any order                    |" << endl;
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "Input any key to exit : ";
            cin >> confirm;
            return ;
        }
        t->displayOrderStatus();
        try
        {
            cout << "1 Next order" << endl;
            cout << "2 Back order" << endl;
            if (t->return_status() == 2 || t->return_status() == 3)
                cout << "3 Finish" << endl;
            cout << "0 Exit" << endl;
            // cout << "sizeNode : " << sizeNodeinLinkList << endl;
            // cout << "len : " << len << endl;
            // cout << "sizeHead : " << sizeHeadLinkList << endl;
            cout << "Input : ";
            cin >> choice;
            if (cin.fail()) 
            {
                throw 1;
            }
            // cout << "input 2 for back"
            if (choice == 1)
            {
                len += 1;
                if (len < sizeNodeinLinkList)
                {
                    t = t->move_next();
                }
                else
                    len = (sizeNodeinLinkList - 1);
            }
            // printf()
            else if (choice == 2)
            {
                len -= 1;
                if (len >= 0)
                    t = t->move_back();
                else
                    len = 0;
            }
            else if (choice == 3 && (t->return_status() == 2 || t->return_status() == 3))
            {
                string nameLL;

                nameLL = t->return_name();
                if (t->move_next() != NULL)
                {
                    t = t->move_next();
                    // len += 1;
                }
                else if (t->move_back() != NULL)
                {
                    t = t->move_back();
                    // len -= 1;
                }
                else
                    t = NULL;

                // cout << "test" << endl;
                delete_LinkedList(nameLL);
                save_data_LinkList("OrderStatusHQDatabase.csv");
                // len -= 1;
            }
            else if (choice == 0)
            {
                break;
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

void headLinkList::displaySendOrderManager()
{
    int len = 0;
    int choice;
    LinkedList *t;

    t = holLinkedList;
    while (1)
    {
        string confirm;
        if (t == NULL)
        {
            system("clear");
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "|                   Don't have any order                    |" << endl;
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "Input any key to exit : ";
            cin >> confirm;
            return ;
        }
        t->displayAll();
        try
        {
            cout << "1 Next order" << endl;
            cout << "2 Back order" << endl;
            cout << "3 Send to staff" << endl;
            cout << "0 Exit" << endl;
            // cout << "sizeNode : " << sizeNodeinLinkList << endl;
            // cout << "len : " << len << endl;
            // cout << "sizeHead : " << sizeHeadLinkList << endl;
            cout << "Input : ";
            cin >> choice;
            if (cin.fail()) 
            {
                throw 1;
            }
            // cout << "input 2 for back"
            if (choice == 1)
            {
                len += 1;
                if (len < sizeNodeinLinkList)
                {
                    t = t->move_next();
                }
                else
                    len = (sizeNodeinLinkList - 1);
            }
            // printf()
            else if (choice == 2)
            {
                len -= 1;
                if (len >= 0)
                    t = t->move_back();
                else
                    len = 0;
            }
            else if (choice == 3)
            {
                string name;

                name = t->return_name();
                int type = t->return_duty();
                if (t->move_next() != NULL)
                {
                    t = t->move_next();
                    // len += 1;
                }
                else if (t->move_back() != NULL)
                {
                    t = t->move_back();
                    // len -= 1;
                }
                else
                    t = NULL;

                // cout << "test" << endl;
                // string a;
                // cout << "test" << endl;
                // cin >> a;

                delete_LinkedList(name, "OrderStaffDatabase.csv", 0, "OrderStatusHQDatabase.csv", 1, "OrderStatusManagerDatabase.csv", 0);
                load_data_other("OrderManagerDatabase.csv");
                save_data_LinkList("OrderManagerDatabase.csv");
                send_order(name, role, id, type);

                // cout << "finish" << endl;
                // cin >> a;
                // len -= 1;
            }
            else if (choice == 0)
            {
                break;
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

void headLinkList::displayOrderStatusManager()
{
    int len = 0;
    int choice;
    LinkedList *t;

    t = holLinkedList;
    while (1)
    {
        string confirm;
        if (t == NULL)
        {
            system("clear");
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "|                   Don't have any order                    |" << endl;
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "input any key to exit : ";
            cin >> confirm;
            return ;
        }
        t->displayOrderStatus();
        try
        {
            cout << "1 Next order" << endl;
            cout << "2 Back order" << endl;
            if (t->return_status() == 2 || t->return_status() == 3)
                cout << "3 Finish" << endl;
            cout << "0 Exit" << endl;
            // cout << "sizeNode : " << sizeNodeinLinkList << endl;
            // cout << "len : " << len << endl;
            // cout << "sizeHead : " << sizeHeadLinkList << endl;
            cout << "Input : ";
            cin >> choice;
            if (cin.fail()) 
            {
                throw 1;
            }
            // cout << "input 2 for back"
            if (choice == 1)
            {
                len += 1;
                if (len < sizeNodeinLinkList)
                {
                    t = t->move_next();
                }
                else
                    len = (sizeNodeinLinkList - 1);
            }
            // printf()
            else if (choice == 2)
            {
                len -= 1;
                if (len >= 0)
                    t = t->move_back();
                else
                    len = 0;
            }
            else if (choice == 3 && (t->return_status() == 2 || t->return_status() == 3))
            {
                string nameLL;
                int status;

                nameLL = t->return_name();
                status = t->return_status();
                if (t->move_next() != NULL)
                {
                    t = t->move_next();
                    // len += 1;
                }
                else if (t->move_back() != NULL)
                {
                    t = t->move_back();
                    // len -= 1;
                }
                else
                    t = NULL;

                if (status == 3)
                {
                    delete_LinkedList(nameLL, "OrderStatusHQDatabase.csv", 3);
                    load_data_other("OrderStatusManagerDatabase.csv");
                    save_data_LinkList("OrderStatusManagerDatabase.csv");
                }
                else
                {
                    delete_LinkedList(nameLL, "OrderStatusHQDatabase.csv", 2);
                    load_data_other("OrderStatusManagerDatabase.csv");
                    save_data_LinkList("OrderStatusManagerDatabase.csv");
                }
                len -= 1;
            }
            else if (choice == 0)
            {
                break;
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


void headLinkList::displayOrderStatusStaff()
{
    int len = 0;
    int choice;
    LinkedList *t;

    t = holLinkedList;
    while (1)
    {
        string confirm;
        if (t == NULL)
        {
            system("clear");
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "|                   Don't have any order                    |" << endl;
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "Input any key to exit : ";
            cin >> confirm;
            return ;
        }
        t->displayAll();
        try
        {
            cout << "1 Next order" << endl;
            cout << "2 Back order" << endl;
            cout << "3 deny order" << endl;
            cout << "4 Finish" << endl;
            cout << "0 Exit" << endl;
            // cout << "sizeNode : " << sizeNodeinLinkList << endl;
            // cout << "len : " << len << endl;
            // cout << "sizeHead : " << sizeHeadLinkList << endl;
            cout << "Input : ";
            cin >> choice;
            if (cin.fail()) 
            {
                throw 1;
            }
            // cout << "input 2 for back"
            if (choice == 1)
            {
                len += 1;
                if (len < sizeNodeinLinkList)
                {
                    t = t->move_next();
                }
                else
                    len = (sizeNodeinLinkList - 1);
            }
            // printf()
            else if (choice == 2)
            {
                len -= 1;
                if (len >= 0)
                    t = t->move_back();
                else
                    len = 0;
            }
            else if (choice == 3)
            {
                string nameLL;

                nameLL = t->return_name();
                if (t->move_next() != NULL)
                {
                    t = t->move_next();
                    // len += 1;
                }
                else if (t->move_back() != NULL)
                {
                    t = t->move_back();
                    // len -= 1;
                }
                else
                    t = NULL;
                delete_LinkedList(nameLL, "OrderStatusManagerDatabase.csv", 3);
                load_data_other("OrderStaffDatabase.csv");
                save_data_LinkList("OrderStaffDatabase.csv");
                len -= 1;
            }
            else if (choice == 4)
            {
                string nameLL;

                nameLL = t->return_name();
                if (t->move_next() != NULL)
                {
                    t = t->move_next();
                    // len += 1;
                }
                else if (t->move_back() != NULL)
                {
                    t = t->move_back();
                    // len -= 1;
                }
                else
                    t = NULL;
                delete_LinkedList(nameLL, "OrderStatusManagerDatabase.csv", 2);
                load_data_other("OrderStaffDatabase.csv");
                save_data_LinkList("OrderStaffDatabase.csv");
                len -= 1;
            }
            else if (choice == 0)
            {
                break;
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

// id : 1000
// container : 1 ---> container : 2