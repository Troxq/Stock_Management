#include <string>
#include <iostream>
#include <vector>
#include "OrderFormatLL.h"

using namespace std;

class headLinkList
{
private:
    LinkedList *holLinkedList;
    int sizeNodeinLinkList;
    int sizeHeadLinkList;

public:
    headLinkList();
    void displaySendOrderManager();
    void delete_LinkedList(string);
    void delete_LinkedList(string, string);
    void add_LinkedList(LinkedList *&);
    void load_data(string);
    void return_name();
    void save_data_LinkList(string);

};

headLinkList::headLinkList()
{
    holLinkedList = NULL;
    sizeNodeinLinkList = 0;
    sizeHeadLinkList = 0;
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

void headLinkList::delete_LinkedList(string nameOwner, string nameFile)
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
            currentPtr->save_data(nameFile);
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

void headLinkList::save_data_LinkList(string nameFile)
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
            myfile << t->return_name() << "," << t->return_size();
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
        cout << "Data has been appended and saved in reverse order." << endl;
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

        string nameLinklist = row[0];
        int size = stoi(row[1]);
        // int sizeLinkList = stoi(row[1]) / 2;

        // cout << "size = " << size << endl;
        // cout << "size \\ 2 = " << size / 2 << endl;
        // cin >> size;
        LinkedList *owner = new LinkedList(nameLinklist, 0);

        if (size > 0)
        {
            for (int i = row.size() - 1; i >= 2; i -= 2)
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
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "|                   Don't have any order                    |" << endl;
            cout << "|-----------------------------------------------------------|" << endl;
            cout << "input any key to exit : ";
            cin >> confirm;
            return ;
        }
        t->displayAll();
        try
        {
            cout << "1 for next order" << endl;
            cout << "2 for back order" << endl;
            cout << "3 for send to staff" << endl;
            cout << "0 for exit" << endl;
            // cout << "sizeNode : " << sizeNodeinLinkList << endl;
            // cout << "len : " << len << endl;
            // cout << "sizeHead : " << sizeHeadLinkList << endl;
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
                delete_LinkedList(name, "OrderStaffDatabase.csv");
                save_data_LinkList("OrderManagerDatabase.csv");
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

