#include <iostream>
#include <string>

using namespace std;

class Headquarter 
{
public:
    virtual void performTask()
    {
        cout << "Performing a Headquarter task" << endl;
    }
};

class Manager : public Headquarter
{
public:
    void performTask() 
    {
        cout << "Performing a manager task" << endl;
    }
    Manager()
    {
        cout << "Constructor for Manager!!!" << endl;
    }
};

class Staff : public Manager
{
public:
    void performTask()
    {
        cout << "Performing a staff task" << endl;
    }
    Staff()
    {
        cout << "Constructor for Staff!!!" << endl;
    }
};

