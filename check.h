#include <iostream>
#include <string>
#include <cstdarg>

using namespace std;

#ifndef CHECK_H
#define CHECK_H


bool check_no_input(int n, ...){ //need number of argument and input string only
    string strInput;
    va_list inputList;
    va_start(inputList, n);
    for(int i=0; i < n; i++){
        strInput = va_arg(inputList, const char *);
        strInput += "\0";
        if(strInput.compare("no_input")==0){
            cout<<"no input"<<endl;
            va_end(inputList);
            return true;
        }
    }
    va_end(inputList);
    return false;
}

#endif