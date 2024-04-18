#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "Login.h"

using namespace std;

int main()
{
    int MainPage_Choice;
    while(true)
    {
        cout << "===== Stock Management System =====" << endl;
        cout << "Choose (1. Login , 2. Exit) : ";
        cin >> MainPage_Choice;

        Role *role = nullptr; 

        switch(MainPage_Choice)
        {
            case 1 : 
                     login(role); // Login Using Pointer to pass parameter
                     role->performTask();
                     role->showNameandRole();
                    if (role->get_role() == "Headquarter")
                    {
                        system("clear");
                        cout << "I am HQ" << endl;
                    }
                    else if (role->get_role() == "Manager")
                    {
                        system("clear");
                        cout << "I am Manager" << endl;
                    }
                    else if (role->get_role() == "Staff")
                    {
                        system("clear");
                        cout << "I am Staff" << endl;
                    }
                     break;
            case 2 : 
                     system("clear");
                     cout << "BYE BYE !!" << endl;
                     return 0;
                     break;
            default : cout << "Choose Again !!" << endl;
        }
        
    }
}
