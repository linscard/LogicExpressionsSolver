#include <iostream>
using namespace std;

#ifndef TP1_NODE_H
#define TP1_NODE_H

template <typename T>
class Node
{
public:
	Node();
    Node(const Node& copy);
    ~Node();

	T item;
	Node<T> *next = nullptr;
	Node<T> *previous = nullptr;
};

template<typename T>
Node<T>::Node(const Node &copy) {
    item = copy.item;
    previous = copy.previous;
    next = copy.next;
}

template<typename T>
Node<T>::~Node() {
    next = nullptr;
    previous = nullptr;
}

template <typename T>
Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
}

#endif // TP1_NODE_H
