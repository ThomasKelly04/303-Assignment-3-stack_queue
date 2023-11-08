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
            std::cout << "Expression is balanced. Added to the queue." << std::endl;
        }
        else {
            std::cout << "Expression is unbalanced. Please enter a valid expression." << std::endl;
        }
    }

    std::cout << "Converting and displaying postfix expressions:" << std::endl;
    while (!expressionManager.infixQueue.empty()) {
        std::string postfixExpression = expressionManager.getNextPostfixExpression();
        std::cout << "Infix: " << inputExpression << " => Postfix: " << postfixExpression << std::endl;
    }

    return 0;
}
