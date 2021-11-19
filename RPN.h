#ifndef REVERSE_POLISH_NOTATION_RPN_H
#define REVERSE_POLISH_NOTATION_RPN_H


#include <string>
#include <map>

class RPN {
 public:
    RPN() = default;

    std::string infixToPostfix(const std::string &);

 protected:
    std::map<char, uint8_t> allOperators = {
            {'(', 255},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3},
    };
};


#endif //REVERSE_POLISH_NOTATION_RPN_H
