#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '*' || c == '(' || c == ')';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string parseExpression(const string& expression) {
    stack<char> operators;
    stack<string> operands;

    for (char c : expression) {
        if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' && getPrecedence(operators.top()) >= getPrecedence(c)) {
                string operand2 = operands.top();
                operands.pop();

                string operand1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                string result = operand1 + operand2 + op;
                operands.push(result);
            }

            if (c == ')') {
                operators.pop();  // Remove the corresponding opening bracket

                while (!operators.empty() && operators.top() != '(') {
                    string operand2 = operands.top();
                    operands.pop();

                    string operand1 = operands.top();
                    operands.pop();

                    char op = operators.top();
                    operators.pop();

                    string result = operand1 + operand2 + op;
                    operands.push(result);
                }
            } else {
                operators.push(c);
            }
        } else {
            operands.push(string(1, c));
        }
    }

    while (!operators.empty()) {
        string operand2 = operands.top();
        operands.pop();

        string operand1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        string result = operand1 + operand2 + op;
        operands.push(result);
    }

    return operands.top();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    string parsedExpression = parseExpression(expression);

    cout << "Parsed expression: " << parsedExpression << endl;

    return 0;
}
