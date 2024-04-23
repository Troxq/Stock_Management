#include <iostream>
#include <string>
#include <cstring>
#include <cstdarg>

using namespace std;

#ifndef CHECK_H
#define CHECK_H


bool check_no_input(int n, ...){ //need number of argument and input string only

    va_list inputList;
    va_start(inputList, n);

    for (int i = 0; i < n; i++) {
        std::string cppString = va_arg(inputList, std::string);
        if (cppString == "no_input") {
            cout<<"no input"<<endl;
            va_end(inputList);
            return true;
        }
    }
    
    va_end(inputList);
    return false;
}

#endif