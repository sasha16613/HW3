// Created by AlexNov on 05.01.2022.

#include "header.h"

bool push_value(string& value, vector<string>& line) {  //Добавляет значение в line
    if (!value.empty()) {
        if (check_value(value))
        {
            line.push_back(value);
            value.clear();
            return true;
        }
        return false;
    }
    return true;
}

bool check_value(const string& num) { //Проверяет является ли значение числом
    return all_of(num.begin(), num.end(), [](char i){return isdigit(i) || i == '.';}) ? true : false;
}

bool calculating_the_expression(stack<string>& symbols, stack<double>& numbers) {
    if (numbers.empty()) {
        cerr << "The entered expression is written with errors1.\n";
        return false;
    }
    string str = symbols.top();
    symbols.pop();
    if (str == "!") {
        double value = numbers.top();
        numbers.top() = -value;
    }
    else if (static_cast<int>(numbers.size()) == 1) {
        cerr << "The entered expression is written with errors2.\n";
        return false;
    }
    else if (str == "/") {
        double value1 = numbers.top();
        numbers.pop();
        double value2 = numbers.top();
        numbers.pop();
        if (value1 == 0) {
            cerr << "Division by zero.\n";
            return false;
        }
        numbers.push(value2 / value1);
    }
    else if (str == "*") {
        double value1 = numbers.top();
        numbers.pop();
        double value2 = numbers.top();
        numbers.pop();
        numbers.push(value2 * value1);
    }
    else if (str == "-") {
        double value1 = numbers.top();
        numbers.pop();
        double value2 = numbers.top();
        numbers.pop();
        numbers.push(value2 - value1);
    }
    else if (str == "+") {
        double value1 = numbers.top();
        numbers.pop();
        double value2 = numbers.top();
        numbers.pop();
        numbers.push(value2 + value1);
    }
    return true;
}
