#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "Login.h"

using namespace std;

int main()
{
    Role *role = nullptr; 
    login(role);
    
    role->performTask();
    role->showNameandRole();
}
