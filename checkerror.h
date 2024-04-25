#ifndef CHECKERROR_H
#define CHECKERROR_H

void checkInputStr(string str)
{
    int i = 0;
    int len = str.length();

    for (i = 0; i < len; i++)
    {
        if (len > 50)
            throw "Error: Invalid input. Please don't input more than 50 character";
        if (!((str[i] >= 0 && str[i] <= 9) || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            throw "Error: Invalid input. Please don't use special character";   
    }
}

#endif