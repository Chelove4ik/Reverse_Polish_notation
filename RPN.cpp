#include "RPN.h"
#include <stack>

std::string RPN::infixToPostfix(const std::string &input) {
    std::string ans;
    std::stack<char> operations;
    char prev = ' ';

    for (char cur: input) {
        if (cur == ' ') {
            continue;
        } else if (cur == '(') {
            operations.push(cur);
        } else if (cur == ')') {
            while (!operations.empty() && operations.top() != '(') {
                ans += ' ';
                ans += operations.top();
                operations.pop();
            }
            if (operations.empty())
                throw std::runtime_error("Error in input");
            operations.pop();
        } else if (priorityOperations.find(cur) != priorityOperations.end()) {
            if (!operations.empty() && operations.top() != '(' &&
                priorityOperations[cur] <= priorityOperations[operations.top()]) {
                ans += ' ';
                ans += operations.top();
                operations.pop();
            }
            operations.push(cur);
        } else {
            if (!(std::isdigit(prev)))
                ans += ' ';
            ans += cur;
        }
        prev = cur;
    }
    while (!operations.empty()) {
        if (operations.top() == '(') {
            throw std::runtime_error("Error in input");
        }
        ans += ' ';
        ans += operations.top();
        operations.pop();
    }
    return !ans.empty() ? ans.substr(1) : std::string();
}

int RPN::solvePostfix(const std::string &input) {
    std::stack<int> stack;
    int tempNum = 0;
    char prev = ' ';
    int a, b;
    for (char cur: input) {
        if (cur == ' ' && std::isdigit(prev)) {
            stack.push(tempNum);
            tempNum = 0;
        } else if (std::isdigit(cur)) {
            tempNum = tempNum * 10 + cur - '0';
        } else {
            if (funcForOperation.find(cur) == funcForOperation.end())
                throw std::runtime_error("Error: unknown operator");
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(funcForOperation[cur](b, a));
        }
        prev = cur;
    }
    return stack.top();
}

int RPN::solveInfix(const std::string &input) {
    return solvePostfix(infixToPostfix(input));
}