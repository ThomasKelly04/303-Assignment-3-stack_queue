// main.cpp

#include <iostream>
#include "expression_manager.h"

int main() {
    ExpressionManager expressionManager;
    std::string inputExpression;

    while (true) {
        std::cout << "Enter an infix expression ('v' to view queue, or 'q' to quit): ";
        std::getline(std::cin, inputExpression);

        if (inputExpression == "q") {
            break;
        }
        else if (inputExpression == "v") {
            // View the current contents of the queue
            std::queue<std::string> tempQueue = expressionManager.infixQueue; // Copy the original queue
            std::cout << "Current contents of the queue:" << std::endl;
            while (!tempQueue.empty()) {
                std::cout << tempQueue.front() << std::endl;
                tempQueue.pop();
            }
            continue; // Skip further processing for 'v'
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
