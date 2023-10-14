#include "TreeNode.h"
#include "Utils.h"
#include "PostFixExpression.h"

#ifndef TP1_TREE_H
#define TP1_TREE_H

class Tree {
public:
    Tree() {
        root = new TreeNode();
    }

    ~Tree() {
        delete root;
    }

    void grow(Stack<char> &item) {
        recursivePush(item, *root);
    }

    void walk();


private:
    Stack<char>* possibleResponse;
    void recursivePush(Stack<char> &item, TreeNode &newRoot) {
        auto* copyOfItem = new Stack<char>(item);

        newRoot.item = copyOfItem;
        newRoot.nodeType = Utils::getSATOperator(item);

        if (newRoot.nodeType == 's'){
            auto* postExp = new PostFixExpression();
            postExp->form(*newRoot.item);
            postExp->solve();
            newRoot.nodeIsTrue = postExp->expressionResult;
            return;
        } else {
            auto* itemWhitTrue = new Stack<char>(item);
            Utils::satToBool(*itemWhitTrue, '1');

            auto* itemWhitFalse = new Stack<char>(item);
            Utils::satToBool(*itemWhitFalse, '0');

            newRoot.right = new TreeNode();
            recursivePush(*itemWhitTrue, *newRoot.right);

            newRoot.left = new TreeNode();
            recursivePush(*itemWhitFalse, *newRoot.left);
        }

        char rightChildResult = newRoot.right->nodeIsTrue;
        char leftChildResult = newRoot.left->nodeIsTrue;
        char intRightChildResult = Utils::charToInteger(rightChildResult);
        char intLeftChildResult = Utils::charToInteger(leftChildResult);

        if (newRoot.nodeType == 'a') {
            int result = intRightChildResult && intLeftChildResult;
            newRoot.nodeIsTrue = Utils::integerToChar(result);
        } else if (newRoot.nodeType == 'e') {
            int result = intRightChildResult || intLeftChildResult;
            newRoot.nodeIsTrue = Utils::integerToChar(result);
        }
    }


    TreeNode *root = nullptr;
};

#endif //TP1_TREE_H
