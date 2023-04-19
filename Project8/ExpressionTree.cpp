//
// Created by Hyokwon Chung on 4/15/23.
//

#include "ExpressionTree.h"

// Define a struct to represent a node in the binary expression tree
//struct Node {
//    string value;
//    Node* left;
//    Node* right;
//};
//struct Node {
//    string value;
//    Node* left;
//    Node* right;
//};
// Helper function to create a new node with the given value
Node* newNode(string value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* newNode(string value, Node* left, Node* right) {
    Node* node = new Node;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int execute(vector<string>& command, const std::map<std::string, int>& symbolTable){
    return(evaluateExpressionTree(constructExpressionTree(command, symbolTable)));
}

// Function to construct a binary expression tree from an input expression
Node* constructExpressionTree(vector<string>& tokens, const map<string, int>& symbolTable) {
    if (tokens.empty()) {
        return nullptr;
    }

    string token = tokens.front();
    tokens.erase(tokens.begin());

    // If token is an operator, pop two operands and create a new subtree

    if (token == "!" || token == "~") {
        Node *left = constructExpressionTree(tokens, symbolTable);

        return newNode(token, left, nullptr);
    }

    else if (token == "+" || token == "-" || token == "*" || token == "/"||
    token == "&&" || token == "||" || token == "<" || token == ">"||
    token == "==" || token == "!=" || token == "<=" || token == ">="||
    token == "!" || token == "~"|| token == "%") {
        Node *left = constructExpressionTree(tokens, symbolTable);

        Node *right = constructExpressionTree(tokens, symbolTable);

        return newNode(token, left, right);
    }
    else {
        // If token is a variable, look it up in the symbol table and replace it with its value
        if (symbolTable.find(token) != symbolTable.end()) {
            return newNode(to_string(symbolTable.at(token)));
        }
        else{//just one integer came in.
            return newNode(token);

        }
    }
}


// Function to evaluate the binary expression tree
int evaluateExpressionTree(Node* root) {
    if (!root) {
        return NULL;
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
        return !leftValue;
    } else if (root->value == "~") {
        return -leftValue;
    } else {
        throw invalid_argument("Invalid operator: " + root->value);
    }
}
