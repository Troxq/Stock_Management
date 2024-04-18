#include <iostream>
#include <fstream>
#include <string>
#include "UserSystem.h"

using namespace std;

int main()
{
    cout << "Register System" << endl;

    string username, password;
    while(true)
    {
        cout << "Enter Username : ";
        cin >> username;

        if(usernameCheck(username, "userdatabase.csv")) // Check Username
        {
            cout << "Username already exists !!" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "Enter Password : ";
    cin >> password;

    ofstream file("userdatabase.csv", ios::app); // open or create a file in append mode

    file << username << "," << password << endl;

    file.close();

    cout << "Create User Successfully" << endl;
}