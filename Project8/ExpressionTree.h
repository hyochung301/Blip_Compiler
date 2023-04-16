//
// Created by Hyokwon Chung on 4/15/23.
//

#ifndef PROJECT8_EXPRESSIONTREE_H
#define PROJECT8_EXPRESSIONTREE_H
#include <iostream>
#include <string>
#include <stack>
using namespace std;


struct ExpressionNode {
    std::string data;
    std::shared_ptr<ExpressionNode> left;
    std::shared_ptr<ExpressionNode> right;

    ExpressionNode(const std::string& d): data(d), left(nullptr), right(nullptr) {}
};

#endif //PROJECT8_EXPRESSIONTREE_H
