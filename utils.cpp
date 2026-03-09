#include <bits/stdc++.h>
using namespace std;
#include "utils.h"
#include "colors.h"

int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout<<red<<"Invalid input, please try Enter a number\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
double getDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout<<red<<"Invalid input, please try Enter a double number\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
std::string getStringInput(const std::string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        if (cin >> value) return value;
        cout<<red<<"Invalid input, please try Enter a valid input\n"<<RESET;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}