// main.cpp

#include <iostream>
#include "expression_manager.h"

int main() {
    ExpressionManager expressionManager;
    std::string inputExpression;

    while (true) {
        std::cout << "Enter an infix expression (or 'q' to quit): ";
        std::getline(std::cin, inputExpression);

        if (inputExpression == "q") {
            break;
        }

        if (expressionManager.isBalanced(inputExpression)) {
            expressionManager.addInfixToQueue(inputExpression);
            int queueSize = expressionManager.infixQueue.size(); // Get the size of the queue
            std::cout << "Expression is balanced. Added to the queue. Queue Size: " << queueSize << std::endl;
        }
        else {
            std::cout << "Expression is unbalanced. Please enter a valid expression." << std::endl;
        }
    }

    std::cout << "Converting and displaying postfix expressions:" << std::endl;
    while (!expressionManager.infixQueue.empty()) {
        std::string infixExpression = expressionManager.infixQueue.front();
        std::string postfixExpression = expressionManager.infixToPostfix(infixExpression);
        std::cout << "Infix: " << infixExpression << " => Postfix: " << postfixExpression << std::endl;
        expressionManager.infixQueue.pop();
    }

    return 0;
}


