#include <iostream>
#include "Stack.h"
using namespace std;

#ifndef TP1_TREENODE_H
#define TP1_TREENODE_H


class TreeNode {
public:
    TreeNode()  {
        right = nullptr;
        left = nullptr;
    }

    TreeNode(const TreeNode& copy) {
        item = copy.item;
        nodeIsTrue = copy.nodeIsTrue;
        nodeType = copy.nodeType;
        right = copy.right;
        left = copy.left;
    }

    ~TreeNode() {
        delete item;
        right = nullptr;
        left = nullptr;
    }

    Stack<char>* item;
    char nodeIsTrue;
    char nodeType;
    TreeNode *right = nullptr;
    TreeNode *left = nullptr;
};

#endif //TP1_TREENODE_H
