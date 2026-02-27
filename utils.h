#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <vector>
#include<string>

int getIntInput(const std::string& prompt);
double getDoubleInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);
template <typename T>
T findMax(const std::vector<T>& items);
#endif