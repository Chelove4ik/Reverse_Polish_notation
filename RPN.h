#ifndef REVERSE_POLISH_NOTATION_RPN_H
#define REVERSE_POLISH_NOTATION_RPN_H


#include <string>
#include <map>
#include <functional>
#include <cmath>

class RPN {
 public:
    RPN() = default;

    std::string infixToPostfix(const std::string &);

    int solvePostfix(const std::string &input);

    int solveInfix(const std::string &input);

 protected:
    std::map<char, uint8_t> priorityOperations = {
            {'(', 255},
            {'+', 0},
            {'-', 0},
            {'*', 1},
            {'/', 1},
            {'^', 2},
    };
    std::map<char, std::function<int(int, int)>> funcForOperation = {
            {'+', [](int a, int b) { return a + b; }},
            {'-', [](int a, int b) { return a - b; }},
            {'*', [](int a, int b) { return a * b; }},
            {'/', [](int a, int b) { return a / b; }},
            {'^', [](int a, int b) { return std::pow(a, b); }},
    };
};


#endif //REVERSE_POLISH_NOTATION_RPN_H
