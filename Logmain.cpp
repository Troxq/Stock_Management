#include <iostream>
#include <string>
#include "Log.h"

void Logmenu()
{
    int choice=0;
    system("clear");
    while(true)
    {
        try
        {
            cout << "We track all of your progress" << endl;
            cout << "What progress you want to see" << endl;
            cout << "[1] Register" << endl;
            cout << "[2] Login" << endl;
            //cout << "[3] import" << endl;
            //cout << "[4] export" << endl;
            cout << "[3] send_order" << endl;
            cout << "[4] confirm_order" << endl;
            cout << "[5] transfer" << endl;
            cout << "Input your choice : " << endl;
            cin >> choice;

            if(cin.fail() || choice > 5 || choice < 1)
            {
                throw 1;
            }

            break;
        }

        catch(...)
        {
            cout << "Choice not available" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    if(choice == 1)
    {
        system("clear");
        regis_show();
    }

    else if(choice == 2)
    {
        system("clear");
        login_show();
    }

    else if(choice == 3)
    {
        system("clear");
        send_order_show();
    }
}   