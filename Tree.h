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
        auto* possibelItemToRespond = new Stack<char>(item);
        possibleResponse = possibelItemToRespond;
        recursivePush(item, *root);
    }

    Stack<char>* possibleResponse;
    char treeResponse;


private:
    void recursivePush(Stack<char> &item, TreeNode &newRoot) {
        auto* newItem = new Stack<char>(item);

        newRoot.item = newItem;
        newRoot.nodeType = Utils::getSATOperator(item);

        if (newRoot.nodeType == 's'){
            auto* postExp = new PostFixExpression();
            postExp->form(*newRoot.item);
            postExp->solve();
            newRoot.nodeIsTrue = postExp->expressionResult;
            treeResponse = newRoot.nodeIsTrue;
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
        int intRightChildResult = Utils::charToInteger(rightChildResult);
        int intLeftChildResult = Utils::charToInteger(leftChildResult);

        if (newRoot.nodeType == 'a') {
            int result = intRightChildResult && intLeftChildResult;
            newRoot.nodeIsTrue = Utils::integerToChar(result);
            treeResponse = newRoot.nodeIsTrue;
        } else if (newRoot.nodeType == 'e') {
            int result = intRightChildResult || intLeftChildResult;
            newRoot.nodeIsTrue = Utils::integerToChar(result);
            treeResponse = newRoot.nodeIsTrue;
            if (result) {
                int ePosition = Utils::getSATOperatorPosition(*newRoot.item, 'e');
                if (intRightChildResult && intLeftChildResult){
                    Utils::changeStackItem(*possibleResponse, 'a', ePosition);
                } else if (intRightChildResult) {
                    Utils::changeStackItem(*possibleResponse, '1', ePosition);
                } else {
                    Utils::changeStackItem(*possibleResponse, '0', ePosition);
                }
            }
        }
    }


    TreeNode *root = nullptr;
};

#endif //TP1_TREE_H
