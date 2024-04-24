#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    string id;
    string name;
};

struct Owner {
    string name;
    vector<Item> items;
};

bool compareItemsById(const Item& a, const Item& b) {
    return a.id < b.id;
}

int main() {
    ifstream file("Database/container_1.csv");

    vector<Owner> owners;
    string line;
    while (getline(file, line)) 
    {
        istringstream iss(line);
        Owner owner;
        string token;
        while (getline(iss, token, ',')) {
            if (token.empty()) continue; 
            if (owner.name.empty()) {
                owner.name = token;
            } else {
                Item item;
                item.id = token;
                getline(iss, item.name, ',');
                owner.items.push_back(item);
            }
        }
        sort(owner.items.begin(), owner.items.end(), compareItemsById);
        owners.push_back(owner);
    }

    for (const auto& owner : owners) {
        cout << "Owner: " << owner.name << endl;
        for (const auto& item : owner.items) {
            cout << "  Item: " << item.name << "        (ID: " << item.id << ")" << endl;
        }
        cout << endl;
    }

    file.close();
    return 0;
}