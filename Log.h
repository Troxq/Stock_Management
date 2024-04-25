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
void import_prod(string, string, string, string);
void export_prod(string, string, string, string);
void transfer_prod(string, string, string, string, string, string);
void send_order(string, string, int, int);
void confirm_order(string, string, int, int);
void regis_show();
void login_show();
void import_prod_show();
void export_prod_show();
void transfer_prod_show();
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
    now += 7 * 3600; 

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

    fout << getdate() << ',' << gettime() << ',' << username << ',' << role << '\n';
}

void login(string username, string role)
{
    fstream fout;

    fout.open("./Logfile/loginlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << gettime() << ',' << username << ',' << role << '\n';
}

void import_prod(string username, string role, string id, string itemID)
{
    fstream fout;

    fout.open("./Logfile/import_prod.csv", ios::out | ios::app);

    fout << getdate() << ',' << gettime() << ',' << username << ',' << role << ',' << itemID << ',' << id << '\n';  
}

void export_prod(string username, string role, string id, string itemID)
{
    fstream fout;

    fout.open("./Logfile/export_prod.csv", ios::out | ios::app);

    fout << getdate() << ',' << gettime() << ',' << username << ',' << role << ',' << itemID << ',' << id << '\n';  
}

void transfer_prod(string username, string role, string itemID, string id_start, string id_receive_and_name, string receive_name)
{
    fstream fout;

    fout.open("./Logfile/transfer_prod.csv", ios::out | ios::app);

    fout << getdate() << ',' << gettime() << ',' << username << ',' << role << ',' << itemID << ',' << id_start << ',' << id_receive_and_name << ',' << receive_name << '\n';
}

void send_order(string name, string role, int containerid, int type)
{
    fstream fout;
    
    fout.open("./Logfile/send_orderlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << gettime() <<',' << name << ',' << role << ',' << containerid << ',' << type << '\n';
}

void confirm_order(string name, string role, int containerid, int type)
{
    fstream fout;

    fout.open("./Logfile/confirm_orderlog.csv", ios::out | ios::app);

    fout << getdate() << ',' << gettime() << ',' << name << ',' << role << ',' << containerid << ',' << type << '\n';
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
        cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << "(" << row[3] << ")" << " has been created!" << '\n';
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
        cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << "(" << row[3] << ")" << " has been login!" << '\n';
    }

    cout << "Put any key to continue";
    cin >> a;
}

void import_prod_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/import_prod.csv", ios::in);

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
        cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << '(' << row[3] << "|id:" << row[4] << ')' << "transfer product id:" << row[5] << "in to container No." << row[4] << endl;
    }

    cout << "Put any key to continue";
    cin >> a;
}

void export_prod_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/export_prod.csv", ios::in);

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
        cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << '(' << row[3] << "|id:" << row[4] << ')' << "export product id:" << row[5] << "from container No." << row[4] << endl;
    }

    cout << "Put any key to continue";
    cin >> a;
}

void transfer_prod_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/transfer_prod.csv", ios::in);

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

        if(strcmp(row[7].c_str(), "None") != 0)
        {
            cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << '(' << row[3] << "|id:" << row[5] << ')' << "export product id:" << row[4] << "Container[" << row[5] << "from User:" << row[6] << "---->" << row[7] << endl;
        }

        else
        {
            cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << '(' << row[3] << "|id:" << row[5] << ')' << "export product id:" << row[4] << "from Container[" << row[5] << "] to Container[" << row[6] << "]" << endl;
        }

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
            cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << "(" << row[3] << ")" << " sent import order to " << "Container[id:" << row[4] << "]" << '\n';
        }

        else if(row[4] == "2")
        {
            cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << "(" << row[3] << ")" << " sent export order to " << "Container[id:" << row[4] << "]" << '\n';
        }

        else if(row[4] == "3")
        {
            cout << "[" << row[0] << "|" << row[1] << "] " << "User : " << row[2] << "(" << row[3] << ")" << " sent transfer order from " << "Container[id:" << row[4] << "]" << "to Container[id:" << row[5] << "]" << '\n';
        }
    }

    cout << "Put any key to continue";
    cin >> a;
}

void confirm_order_show()
{
    string a;
    fstream fin;
    fin.open("./Logfile/confirm_orderlog.csv", ios::in);

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
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " confirm import order from" << "Container[id:" << row[3] << "]" << '\n';
        }

        else if(row[4] == "2")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " confirm export order from" << "Container[id:" << row[3] << "]" << '\n';
        }

        else if(row[4] == "3")
        {
            cout << "[" << row[0] << "] " << "User : " << row[1] << "(" << row[2] << ")" << " confirm transfer order from " << "Container[id:" << row[3] << "]" << "to Container[id:" << row[4] << "]" << '\n';
        }
    }

    cout << "Put any key to continue";
    cin >> a;
}

#endif

    



