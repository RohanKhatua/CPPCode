#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a node in the abstract syntax tree
struct ASTNode {
    string value;
    ASTNode* left;
    ASTNode* right;
};

// Function to create a new AST node
ASTNode* createNode(string value, ASTNode* left = nullptr, ASTNode* right = nullptr) {
    ASTNode* newNode = new ASTNode;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// Function to traverse the abstract syntax tree and generate three-address code
void generateThreeAddressCode(ASTNode* node, vector<string>& code) {
    if (node != nullptr) {
        generateThreeAddressCode(node->left, code);
        generateThreeAddressCode(node->right, code);
        
        string result = "t" + to_string(code.size() + 1);
        string op = node->value;
        string leftOperand = (node->left != nullptr) ? node->left->value : "";
        string rightOperand = (node->right != nullptr) ? node->right->value : "";
        
        string statement;
        
        if (op == "+") {
            statement = result + " = " + leftOperand + " + " + rightOperand;
        } else if (op == "-") {
            statement = result + " = " + leftOperand + " - " + rightOperand;
        } else if (op == "*") {
            statement = result + " = " + leftOperand + " * " + rightOperand;
        } else if (op == "/") {
            statement = result + " = " + leftOperand + " / " + rightOperand;
        } else {
            statement = result + " = " + op;
        }
        
        code.push_back(statement);
        
        node->value = result;
    }
}

// Function to print the generated three-address code
void printThreeAddressCode(const vector<string>& code) {
    cout << "Three-Address Code:\n";
    for (const auto& statement : code) {
        cout << statement << endl;
    }
}

// Function to build the abstract syntax tree from the input expression
ASTNode* buildAST(const string& expression) {
    stack<ASTNode*> operands;
    stack<string> operators;
    
    for (const auto& token : expression) {
        if (isdigit(token)) {
            operands.push(createNode(string(1, token)));
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            operators.push(string(1, token));
        } else if (token == ')') {
            ASTNode* rightOperand = operands.top();
            operands.pop();
            ASTNode* leftOperand = operands.top();
            operands.pop();
            string op = operators.top();
            operators.pop();
            
            operands.push(createNode(op, leftOperand, rightOperand));
        }
    }
    
    return operands.top();
}

// Function to calculate the expression using the abstract syntax tree
int calculateExpression(ASTNode* node) {
    if (node->left == nullptr && node->right == nullptr) {
        return stoi(node->value);
    }
    
    int leftOperand = calculateExpression(node->left);
    int rightOperand = calculateExpression(node->right);
    
    string op = node->value;
    
    if (op == "+") {
        return leftOperand + rightOperand;
    } else if (op == "-") {
        return leftOperand - rightOperand;
    } else if (op == "*") {
        return leftOperand * rightOperand;
    } else if (op == "/") {
        return leftOperand / rightOperand;
    }
    
    return 0;
}

int main() {
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;
    
    ASTNode* root = buildAST(expression);
    
    vector<string> threeAddressCode;
    generateThreeAddressCode(root, threeAddressCode);
    
    printThreeAddressCode(threeAddressCode);
    
    int result = calculateExpression(root);
    cout << "Result: " << result << endl;
    
    return 0;
}
