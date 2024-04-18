#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

void split(string &, char, string &, string &, string &); // Function to split username and password

bool usernameCheck(string &, string &); // Check if username exists

bool roleCheck(string &, string &, string);

void split(string &line, char separate, string &username, string &password, string &role)
{
    int pos1 = line.find(separate); 
    int pos2 = line.find(separate, pos1 + 1); 

    if (pos1 != string::npos && pos2 != string::npos)
    {
        username = line.substr(0, pos1);
        password = line.substr(pos1 + 1, pos2 - pos1 - 1);
        role = line.substr(pos2 + 1);
    }
}

bool usernameCheck(string &username, string filename)
{
    ifstream file(filename); // open userdatabase file
    
    string line;

    while(getline(file, line))
    {
        string datausername, datapassword, datarole;
        split(line, ',', datausername, datapassword, datarole);
        if(datausername == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool roleCheck(string &role, string &username, string filename)
{
    ifstream file(filename); // open userdatabase file
    
    string line;

    while(getline(file, line))
    {
        string datausername, datapassword, datarole;
        split(line, ',', datausername, datapassword, datarole);
        if(datausername == username && datarole == role)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}