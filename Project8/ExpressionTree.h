//
// Created by Hyokwon Chung on 4/15/23.
//

#ifndef PROJECT8_EXPRESSIONTREE_H
#define PROJECT8_EXPRESSIONTREE_H
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
};

Node* constructExpressionTree(const vector<string>& tokens); //when passed in a vector command, it creates a tree accordingly, returns the node of the root
int evaluateExpressionTree(Node* root); //when passed in  a tree, it performs the operations, returns the int value.
int execute(const vector<string>& tokens);


#endif //PROJECT8_EXPRESSIONTREE_H
