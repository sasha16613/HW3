// Created by AlexNov on 05.01.2022.

#ifndef HW3_HEADER_H
#define HW3_HEADER_H

#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <exception>
#include <algorithm>
using namespace std;

bool push_value(string& num, vector<string>& in);

bool check_value(const string& num);

bool calculating_the_expression(stack<string>& st_func, stack<double>& st_val);

#endif //HW3_HEADER_H
