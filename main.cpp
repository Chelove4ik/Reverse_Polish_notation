#include <iostream>
#include "RPN.h"

int main() {
    using namespace std;
    string str;
    getline(std::cin, str);

    auto rpn = RPN();
    string postfix = rpn.infixToPostfix(str);
    cout << postfix << endl;
    std::cout << rpn.solvePostfix(postfix);
    return 0;
}
