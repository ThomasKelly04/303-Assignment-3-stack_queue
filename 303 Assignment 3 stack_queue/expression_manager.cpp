#include "expression_manager.h"
#include <iostream>
#include <cctype>
#include <unordered_map>
#include <stack>

ExpressionManager::ExpressionManager() {}

bool ExpressionManager::isBalanced(const std::string& expression) {
    std::stack<char> charStack;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            charStack.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (charStack.empty() || !arePairs(charStack.top(), c)) {
                return false;
            }
            charStack.pop();
        }
    }

    return charStack.empty();
}

bool ExpressionManager::arePairs(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

std::string ExpressionManager::infixToPostfix(const std::string& infixExpression) {
    std::string postfix;
    std::stack<char> operatorStack;

    // Operator precedence
    std::unordered_map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;
    precedence['*'] = precedence['/'] = precedence['%'] = 2;

    for (char token : infixExpression) {
        if (std::isalnum(token)) {
            postfix += token;  // Output operands directly
        }
        else if (token == '(') {
            operatorStack.push(token);
        }
        else if (token == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();  // Pop the opening parenthesis
            }
        }
        else if (isOperator(token)) {
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                precedence[token] <= precedence[operatorStack.top()]) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(token);
        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

bool ExpressionManager::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

void ExpressionManager::addInfixToQueue(const std::string& infixExpression) {
    infixQueue.push(infixExpression);
}

std::string ExpressionManager::getNextPostfixExpression() {
    std::string infixExpression = infixQueue.front();
    infixQueue.pop();
    return infixToPostfix(infixExpression);
}