//
// Created by Hyokwon Chung on 4/15/23.
//

#ifndef PROJECT8_EXPRESSIONTREE_H
#define PROJECT8_EXPRESSIONTREE_H
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
};
Node* newNode(string value);
Node* newNode(string value, Node* left, Node* right);
Node* constructExpressionTree(vector<string>& tokens, const std::map<std::string, int>& symbolTable);
 //when passed in a vector command, it creates a tree accordingly, returns the node of the root
int evaluateExpressionTree(Node* root); //when passed in  a tree, it performs the operations, returns the int value.
int execute(vector<string>& tokens, const std::map<std::string, int>& symbolTable);


#endif //PROJECT8_EXPRESSIONTREE_H
