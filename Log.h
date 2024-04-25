#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#ifndef LOG_H
#define LOG_H
using namespace std;

string getdate();
string gettime();
void regis(string, string);
void login(string, string);
void send_order(string, string, int, int);
void confirm_order(string, string, int, int);
void regis_show();
void login_show();
void send_order_show();
void confirm_order_show();

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

string gettime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int hours = ltm->tm_hour;
    int minutes = ltm->tm_min;
    int seconds = ltm->tm_sec;

    stringstream ss;
    ss << setfill('0') << setw(2) << hours << ":" 
       << setfill('0') << setw(2) << minutes << ":" 
       << setfill('0') << setw(2) << seconds;
    return ss.str();
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

    fout << getdate() << gettime() << ',' << username << ',' << role << "\n";
}

void send_order(string name, string role, int containerid, int type)
{
    fstream fout;
    
    fout.open("./Logfile/send_orderlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << name << ',' << role << ',' << containerid << ',' << type << '\n';
}

void confirm_order(string name, string role, int containerid, int type)
{
    fstream fout;

    fout.open("./Logfile/confirm_orderlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << name << ',' << role << ',' << containerid << ',' << type << '\n';
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
        cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " has been created!" << endl;
    }

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
        cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " has been login!" << endl;
    }

    cout << "Put any key to continue";
    cin >> a;
}

void send_order_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/send_orderlog.csv", ios::in);

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
        
        if(row[4] == "1")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " sent import order to " << "Container[id:" << row[3] << "]" << endl;
        }

        else if(row[4] == "2")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " sent export order to " << "Container[id:" << row[3] << "]" << endl;
        }

        else if(row[4] == "3")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " sent transfer order from " << "Container[id:" << row[3] << "]" << "to Container[id:" << row[4] << "]" << endl;
        }
    }

    cout << "Put any key to continue";
    cin >> a;
}

void confirm_order_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/send_orderlog.csv", ios::in);

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
        
        if(row[4] == "1")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " confirm import order from" << "Container[id:" << row[3] << "]" << endl;
        }

        else if(row[4] == "2")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " confirm export order from" << "Container[id:" << row[3] << "]" << endl;
        }

        else if(row[4] == "3")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " confirm transfer order from " << "Container[id:" << row[3] << "]" << "to Container[id:" << row[4] << "]" << endl;
        }
    }

    cout << "Put any key to continue";
    cin >> a;
}

#endif

    



