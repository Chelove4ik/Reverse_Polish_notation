#include "RPN.h"
#include <stack>
#include <string>

std::string RPN::infixToPostfix(const std::string &infix) {
    std::string ans;
    std::stack<char> operations;
    char prev = ' ';

    for (char cur: infix) {
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
        } else if (allOperators.find(cur) != allOperators.end()) {
            if (!operations.empty() && operations.top() != '(' && allOperators[cur] <= allOperators[operations.top()]) {
                ans += ' ';
                ans += operations.top();
                operations.pop();
            }
            operations.push(cur);
        } else {
            if (!(prev - '0' >= 0 && prev - '0' <= 9))
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
