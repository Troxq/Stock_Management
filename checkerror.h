#ifndef CHECKERROR_H
#define CHECKERROR_H

int checkInputStr(string str)
{
    int i = 0;
    int len = str.length();

    for (i = 0; i < len; i++)
    {
        if (len > 50)
            return 1;
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            return 2;
    }
    return 0;
}

int checkInputNum(string str)
{
    int i = 0;
    int len = str.length();

    for (i = 0; i < len; i++)
    {
        if (len > 50)
            return 1;
        if (!(str[i] >= '0' && str[i] <= '9'))
            return 2;
    }
    return 0;
}

int checkIdManager(int id)
{
    ifstream fin;

    fin.open("userdatabase.csv");

    vector<string> row;
    string line, word;

    while (getline(fin, line))
    {
        row.clear();

        stringstream s(line);
        
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        if (row[2] == "Manager")
        {
            if (stoi(row[3]) == id)
            {
                fin.close();
                return 0;
            }
        }
    }
    return 1;
}


vector<vector<string>> read_file_and_return_container_vector1(const string& container_filename) {
    ifstream file(container_filename);
    vector<vector<string>> data;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    file.close();
    
    return data;

}
int check_item_id_exist(string item_id){
    string HQfilename = "Database/HQ.csv";
    ifstream file(HQfilename);
    vector<vector<string>> HQ_data;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        HQ_data.push_back(row);
    }

    file.close();

    //get current id
    string container_filename_prefix = "Database/container_";
    string container_filename_suffix = ".csv";

    for(int i = 0; i < HQ_data[1].size();i++){
        string container_name = HQ_data[1][i];
        //cout<<"container_name is "<< container_name<<endl;
        string full_container_filename = container_filename_prefix + container_name + container_filename_suffix;
        vector<vector<string>> container_data = read_file_and_return_container_vector1(full_container_filename);
        for(const auto& row : container_data){
            for(int i = 1; i < row.size(); i+=2){
                if(item_id.compare(row[i])==0){
                    return 1;
                }
            }
        }
    }
    return 0;
}

#endif