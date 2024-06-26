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
            cout << "|-------------------------------|" << endl;
            cout << "| We track all of your progress |" << endl;
            cout << "| What progress you want to see |" << endl;
            cout << "|-------------------------------|" << endl << endl;;
            cout << "[1] Register" << endl;
            cout << "[2] Login" << endl;
            cout << "[3] import" << endl;
            cout << "[4] export" << endl;
            cout << "[5] transfer" << endl;
            cout << "[6] send_order" << endl;
            cout << "[7] confirm_order" << endl;
            cout << "Input your choice : ";
            cin >> choice;

            if(cin.fail() || choice > 7 || choice < 1)
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
        import_prod_show();
    }

    else if(choice == 4)
    {
        system("clear");
        export_prod_show();
    }

    else if(choice == 5)
    {
        system("clear");
        transfer_prod_show();
    }

    else if(choice == 6)
    {
        system("clear");
        send_order_show();
    }

    else if(choice == 7)
    {
        system("clear");
        confirm_order_show();
    }
}   