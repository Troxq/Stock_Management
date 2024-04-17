#include <iostream>
#include <string>

using namespace std;

class Role
{
public:
    virtual void performTask() = 0;
    virtual void showNameandRole() = 0;
};

class Headquarter : public Role
{
public:
    string username, role;
    void performTask()
    {
        cout << "Performing a Headquarter task" << endl;
    }
    Headquarter(string username, string role)
    {
        cout << "Constructor for Headquarter!!!" << endl;
        this->username = username;
        this->role = role;
    }
    void showNameandRole()
    {
        cout << "NAME : " << this->username << " ROLE : "<< this->role << endl;
    }
};
class Manager : public Headquarter
{
public:
    string username, role;
    void performTask() 
    {
        cout << "Performing a manager task" << endl;
    }
    Manager(string username, string role):Headquarter(username,role)
    {
        cout << "Constructor for Manager!!!" << endl;
        this->username = username;
        this->role = role;
    }
    void showNameandRole()
    {
        cout << "NAME : " << this->username << " ROLE : "<< this->role << endl;
    }
};

class Staff : public Manager
{
public:
    string username, role;
    void performTask()
    {
        cout << "Performing a staff task" << endl;
    }
    Staff(string username, string role):Manager(username,role)
    {
        cout << "Constructor for Staff!!!" << endl;
        this->username = username;
        this->role = role;
    }
    void showNameandRole()
    {
        cout << "NAME : " << this->username << " ROLE : "<< this->role << endl;
    }
};

