#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#ifndef LOG_H
#define LOG_H
using namespace std;

string getdate();
void regis(string, string);
void login(string, string);
void regis_show();
void login_show();

string getdate()
{
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    
    int day = timeinfo->tm_mday;
    int month = timeinfo->tm_mon + 1; 
    int year = (timeinfo->tm_year + 1900) % 100;

    string d = to_string(day);
    string m = to_string(month);
    string y = to_string(year);    

    return d + '/' + m + '/' + y;
}

void regis(string username, string role)
{   
    fstream fout;

    fout.open("./Logfile/registerlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << username << ',' << role << "\n";
}

void login(string username, string role)
{
    fstream fout;

    fout.open("./Logfile/loginlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << username << ',' << role << "\n";
}

void regis_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/registerlog.csv", ios::in);

    vector<string> row; 
    string line, word, temp;
  
    while (getline(fin, line)) 
    {
        row.clear(); 
        stringstream s(line); 
        while (getline(s, word, ',')) 
        {
            row.push_back(word); 
        }
    }

    cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " has been reated!" << endl;
    cout << "Put any key to continue";
    cin >> a;
}

void login_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/loginlog.csv", ios::in);

    vector<string> row; 
    string line, word, temp;
  
    while (getline(fin, line)) 
    {
        row.clear(); 
        stringstream s(line); 
        while (getline(s, word, ',')) 
        {
            row.push_back(word); 
        }
    }

    cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " has been login!" << endl;
    cout << "Put any key to continue";
    cin >> a;
}

#endif

    



