#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include "Login.h"

using namespace std;

int main()
{
    Headquarter *role = nullptr; 
    login(role);

    role->performTask();
}
