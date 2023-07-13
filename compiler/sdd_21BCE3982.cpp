#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to perform the operation based on the operator
int performOperation(int operand1, int operand2, char op) {
    if (op == '+')
        return operand1 + operand2;
    else if (op == '-')
        return operand1 - operand2;
    else if (op == '*')
        return operand1 * operand2;
    else if (op == '/')
        return operand1 / operand2;
    else {
        std::cout << "Error: Invalid operator" << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Function to evaluate the expression and calculate the value
int evaluateExpression(const std::string& expression) {
    std::stack<int> operandStack;
    std::stack<char> operatorStack;

    std::cout << "Stack\t\tInput\t\tAction" << std::endl;

    for (char ch : expression) {
        if (isspace(ch)) {
            continue;  // Ignore spaces
        }
        else if (isdigit(ch)) {
            operandStack.push(ch - '0');  // Convert char to int
        }
        else if (isOperator(ch)) {
            std::cout << "-------------------------------------------------" << std::endl;
            // Display stack contents
            std::stack<int> tempOperandStack = operandStack;
            std::stack<char> tempOperatorStack = operatorStack;

            while (!tempOperandStack.empty()) {
                std::cout << tempOperandStack.top() << " ";
                tempOperandStack.pop();
            }

            std::cout << "\t\t" << ch << "\t\tPush operator" << std::endl;

            while (!tempOperatorStack.empty() && tempOperatorStack.top() != '(' && ((ch == '+' || ch == '-') || (ch == '*' && (tempOperatorStack.top() == '*' || tempOperatorStack.top() == '/')))) {
                char topOperator = tempOperatorStack.top();
                tempOperatorStack.pop();

                if (operandStack.size() < 2) {
                    std::cout << "Error: Invalid expression" << std::endl;
                    exit(EXIT_FAILURE);
                }

                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result = performOperation(operand1, operand2, topOperator);
                operandStack.push(result);
            }

            operatorStack.push(ch);
        }
        else if (ch == '(') {
            operatorStack.push(ch);
        }
        else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                char topOperator = operatorStack.top();
                operatorStack.pop();

                if (operandStack.size() < 2) {
                    std::cout << "Error: Invalid expression" << std::endl;
                    exit(EXIT_FAILURE);
                }

                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result = performOperation(operand1, operand2, topOperator);
                operandStack.push(result);
            }

            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
            else {
                std::cout << "Error: Invalid expression" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else {
            std::cout << "Error: Invalid character '" << ch << "' in expression" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    while (!operatorStack.empty()) {
        if (operandStack.size() < 2) {
            std::cout << "Error: Invalid expression" << std::endl;
            exit(EXIT_FAILURE);
        }

        char topOperator = operatorStack.top();
        operatorStack.pop();

        int operand2 = operandStack.top();
        operandStack.pop();
        int operand1 = operandStack.top();
        operandStack.pop();

        int result = performOperation(operand1, operand2, topOperator);
        operandStack.push(result);
    }

    if (operandStack.size() != 1) {
        std::cout << "Error: Invalid expression" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "-------------------------------------------------" << std::endl;
    // Display stack contents
    std::stack<int> tempOperandStack = operandStack;
    std::stack<char> tempOperatorStack = operatorStack;

    while (!tempOperandStack.empty()) {
        std::cout << tempOperandStack.top() << " ";
        tempOperandStack.pop();
    }

    std::cout << "\t\t\tFinal result" << std::endl;

    while (!tempOperatorStack.empty()) {
        std::cout << "\t";
        tempOperatorStack.pop();
    }

    return operandStack.top();
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    int result = evaluateExpression(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
