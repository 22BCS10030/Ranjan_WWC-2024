#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> stack;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string test;
    std::cout << "Enter a string of parentheses: ";
    std::cin >> test;

    if (isValidParentheses(test)) {
        std::cout << "The parentheses are valid.\n";
    } else {
        std::cout << "The parentheses are not valid.\n";
    }

    return 0;
}
