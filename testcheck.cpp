#include <iostream>
#include "check.h"

using namespace std;

int main(){
    string teststr = "no_input";
    if(check_no_input(3, "pop", teststr, "hello")){
        cout<<"it's true";
    }
    return 0;

}