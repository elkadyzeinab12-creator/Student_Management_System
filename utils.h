#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <vector>
#include<string>

int getIntInput(const std::string& prompt);
double getDoubleInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);
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
template <typename V>
V findMin(const std::vector<V>& items) {
    V min = items[0];
    for (int i = 1; i < items.size(); i++)
        if (items[i] < min)
            min = items[i];
    return min;
}
#endif