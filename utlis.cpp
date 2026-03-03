#include <bits/stdc++.h>
using namespace std;
#include "utils.h"
#define red "\033[1;31m"
#define RESET   "\033[0m"

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
template <typename T>
T findMax(const std::vector<T>& items) {
    T max = items[0];
    for (int i = 1; i < items.size(); i++) {
        if (items[i] > max) {
            max = items[i];
        }
    }
    return max;
}