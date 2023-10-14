#include "TreeNode.h"
#include "Utils.h"

#ifndef TP1_TREE_H
#define TP1_TREE_H

class Tree {
public:
    Tree();

    Tree();
    ~Tree();

    void push(char &item);
    void walk();


private:
    void recursivePush(char &item);


TreeNode<char*> *root = nullptr;
};

template<typename T>
void Tree::push(char &item) {
    char satOperator = Utils::getSATOperator(item);
    root = new TreeNode<T>;
    root->item = *new Stack<char>(item);
    root->nodeType = satOperator;
    recursivePush(item);
}

// Definitions
template<typename T>
void Tree::recursivePush(T &item) {
    char satOperator = Utils::getSATOperator(item);

    if (satOperator != 's') {
        auto* stackWithFalse = new Stack<char>(item);
        auto* stackWithTrue = new Stack<char>(item);
        Utils::satToBool(*stackWithFalse, '0');
        stackWithTrue = Utils::satToBool(*stackWithTrue, '1');
        root->left = new TreeNode<T>;;
        root->right = new TreeNode<T>;;
        root->left->item = *stackWithFalse;
        root->right->item = *stackWithTrue;

//        recursivePush(stackWithFalse);
//        recursivePush(stackWithTrue);
    } else {
        return;
    }
}

//template<typename T>
//void Tree<T>::push(Stack<char> item) {
//    recursivePush(&item, *root);
//}

template<typename T>
Tree::Tree() {
    root = nullptr;
}


#endif //TP1_TREE_H
