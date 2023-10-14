#include <iostream>
using namespace std;

#ifndef TP1_TREENODE_H
#define TP1_TREENODE_H

template <typename T>
class TreeNode {
public:
    TreeNode();
    TreeNode(const TreeNode& copy);
    ~TreeNode();

    T* item;
    char nodeIsTrue;
    char nodeType;
    TreeNode<T> *right = nullptr;
    TreeNode<T> *left = nullptr;
};

template<typename T>
TreeNode<T>::~TreeNode() {
    delete item;
    right = nullptr;
    left = nullptr;

}

template<typename T>
TreeNode<T>::TreeNode(const TreeNode &copy) {
    item = copy.item;
    nodeIsTrue = copy.nodeIsTrue;
    nodeType = copy.nodeType;
    right = copy.right;
    left = copy.left;

}

template<typename T>
TreeNode<T>::TreeNode() {
    right = nullptr;
    left = nullptr;
}

#endif //TP1_TREENODE_H
