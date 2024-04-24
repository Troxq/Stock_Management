#include <iostream>

using namespace std;

string getInputWithoutSpaces() {
    string input;
    char ch;
    cout << "Enter text without spaces: ";
    while (cin.get(ch) && ch != '\n') {
        if (ch != ' ') {
            input += ch;
        }
    }
    return input;
}

int main() {
    string text = getInputWithoutSpaces();
    cout << "You entered: " << text << endl;
    return 0;
}