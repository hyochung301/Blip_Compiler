//
// Created by Hyokwon Chung on 4/15/23.
//

#include "ExpressionTree.h"

// Define a struct to represent a node in the binary expression tree
struct Node {
    string value;
    Node* left;
    Node* right;
};

// Helper function to create a new node with the given value
Node* newNode(string value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int execute(const vector<string>& command){
    return(evaluateExpressionTree(constructExpressionTree(command)));
}

// Function to construct a binary expression tree from an input expression
Node* constructExpressionTree(const vector<string>& tokens) {
    stack<Node*> nodeStack;

    for (const string& token : tokens) {
        Node* newNode = ::newNode(token);

        // If token is an operator, pop two operands and create a new subtree

        if (token == "!" || token == "~") {
            Node* operand = nodeStack.top();
            nodeStack.pop();

            newNode->left = operand;
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/"||
        token == "&&" || token == "||" || token == "<" || token == ">"||
        token == "==" || token == "!=" || token == "<=" || token == ">="||
        token == "!" || token == "~") {
            Node *right = nodeStack.top();
            nodeStack.pop();
            Node *left = nodeStack.top();
            nodeStack.pop();

            newNode->left = left;
            newNode->right = right;
        }

        nodeStack.push(newNode);
    }

    return nodeStack.top();
}

// Function to evaluate the binary expression tree
int evaluateExpressionTree(Node* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return stoi(root->value);
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    if (root->value == "+") {
        return leftValue + rightValue;
    } else if (root->value == "-") {
        return leftValue - rightValue;
    } else if (root->value == "*") {
        return leftValue * rightValue;
    } else if (root->value == "/") {
        return leftValue / rightValue;
    }else if (root->value == "%") {
        return leftValue % rightValue;
    } else if (root->value == "<") {
        return leftValue < rightValue;
    } else if (root->value == ">") {
        return leftValue > rightValue;
    } else if (root->value == "==") {
        return leftValue == rightValue;
    } else if (root->value == "!=") {
        return leftValue != rightValue;
    } else if (root->value == "<=") {
        return leftValue <= rightValue;
    } else if (root->value == ">=") {
        return leftValue >= rightValue;
    } else if (root->value == "&&") {
        return leftValue && rightValue;
    } else if (root->value == "||") {
        return leftValue || rightValue;
    } else if (root->value == "!") {
        return !rightValue;
    } else if (root->value == "~") {
        return ~rightValue;
    } else {
        throw invalid_argument("Invalid operator: " + root->value);
    }
}
