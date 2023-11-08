#pragma once
// expression_manager.h

#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <string>
#include <stack>
#include <queue>

class ExpressionManager {
public:
    ExpressionManager();
    void processInfixExpression(const std::string& infixExpression);
    bool isBalanced(const std::string& expression);
    std::string infixToPostfix(const std::string& infixExpression);
    void addInfixToQueue(const std::string& infixExpression);
    std::string getNextPostfixExpression();
    std::queue<std::string> infixQueue;

private:
    std::stack<char> operatorStack;
    bool arePairs(char open, char close);
    bool isOperator(char c); 
};

#endif
