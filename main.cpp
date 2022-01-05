// Created by AlexNov on 05.01.2022.

#include "header.h"

int main()
{
    stack <string> symbols;
    stack <double> numbers;
    string input;
    string value;
    vector<string> line;
    map <string, int> priority = {
            {"(", 1}, {")", 1}, {"!", 2},
            {"*", 3}, {"/", 3}, {"+", 4}, {"-", 4}};
    cout << "Enter a mathematical expression.\n";
    getline(cin, input);
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    int checking_brackets = 0; //Счетчик для проверки скобок
    string checks = "()*/+-";
    for (int i = 0; i != static_cast<int>(input.size()); i++) {  //Разбиваем строку на числа и знаки
        if (checks.find(input[i]) != -1){  //Выполняется, когда символ - знак
            if (!push_value(value, line)) {  //Добавляет число в line
                cerr << "The entered expression is written with errors.\n";
                return 1;
            }
            string str (1, input[i]); //Из char делаем string
            line.push_back(str);   //Добавляет знак в line
            if (input[i] == '(')
                checking_brackets++;
            if (input[i] == ')')
            {
                checking_brackets--;
                if (checking_brackets < 0) {
                    cerr << "The entered expression is written with errors.\n";
                    return 1;
                }
            }
        } else {
            value += input[i];
            if(i == static_cast<int>(input.size()) - 1) { //Добавление последнего числа в line
                if (!push_value(value, line)) {
                    cerr << "The entered expression is written with errors.\n";
                    return 1;
                }
            }
        }

    }
    if (checking_brackets != 0) {
        cerr << "The entered expression is written with errors.\n";
        return 1;
    }

    //Вычисляем введенное выражение
    for (auto i = 0; i != static_cast<int>(line.size()); ++i) {
        string str = line[i];
        if (priority.find(str) != priority.end()) { //Символ не число
            if (str == ")") {
                while (symbols.top() != "(")
                    if (!calculating_the_expression(symbols, numbers)) return 2;
                symbols.pop();
                continue;
            }
            if (symbols.empty()) {
                if (str == "-" && numbers.empty()) {
                    symbols.push("!");
                    continue;
                }
                symbols.push(str);
                continue;
            }
            if (line[i - 1] == "(") {
                if (str == "-") {
                    symbols.push("!");
                    continue;
                }
            }
            while (priority[symbols.top()] <= priority[str]) { //Выполняем операции большего приоритета до данной операции
                if (symbols.top() == "(") break;
                if (!calculating_the_expression(symbols, numbers)) return 2;
                if (symbols.empty()) break;
            }
            symbols.push(str);
        }
        else numbers.push(stod(str));
    }
    while (!symbols.empty())  //Выводим результат
        if (!calculating_the_expression(symbols, numbers)) return 2;
    cout << "Answer: " << numbers.top();
    return 0;
}
