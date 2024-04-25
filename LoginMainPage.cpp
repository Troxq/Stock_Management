#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
// #include "OrderFormat.h"
// #include "OrderFormatHEADLL.h"
#include "Login.h"


using namespace std;

int main()
{
    initCSV(); // initialize file if it doesn't exist create new file
    initOrderCSV();

    int MainPage_Choice;
    while(true)
    {
        cout << "|=========Stock Management System=========|" << endl;
        cout << "|>>=============== Login ===============<<|" << endl << endl;
        
        while (true) 
        {
            cout << "Choose (1. Login , 2. Exit) : ";
            cin >> MainPage_Choice;
            if (!cin.fail()) 
            {
                break;
            } 
            else 
            {
                cin.clear();
                cin.ignore(10, '\n');
                cout << "Invalid input. Please enter an integer (1|2).\n";
            }
        }

        Role *role = nullptr; 

        switch(MainPage_Choice)
        {
            case 1 : 
                     login(role); // Login Using Pointer to pass parameter
                    //  role->performTask();
                     role->showNameandRole();
                    if (role->get_role() == "Headquarter")
                    {
                        system("clear");
                        cout << "I am HQ" << endl;
                        role->mainMenu();
                    }
                    else if (role->get_role() == "Manager")
                    {
                        system("clear");
                        cout << "I am Manager" << endl;
                        role->mainMenu();
                    }
                    else if (role->get_role() == "Staff")
                    {
                        system("clear");
                        cout << "I am Staff" << endl;
                        role->mainMenu();
                    }
                     break;
            case 2 : 
                     system("clear");
                     cout << "BYE BYE !!" << endl;
                     return 0;
                     break;
            default : cout << "Choose Again !!" << endl;
        }
        delete(role);
    }
}
