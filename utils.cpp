#include <bits/stdc++.h>
using namespace std;
#include "utils.h"
#include "colors.h"

/*int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout<<red<<"Invalid input, please try Enter a number\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}*/
int getIntInput(const std::string& prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        char extra;

        if (ss >> value && !(ss>>extra)) {
            return value;
        }

        cout<<red<<"Invalid input, please try Enter a number\n"<<RESET;

    }
}

double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        cout<<red<<"Invalid input, please try Enter a double number\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
std::string getStringInput(const std::string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        cout<<red<<"Invalid input, please try Enter a valid input\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
char getCharInput(const std::string& prompt) {
    char value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout<<red<<"Invalid input, please try Enter a char number\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}
