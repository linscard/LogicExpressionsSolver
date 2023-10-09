#include <iostream>
using namespace std;

#ifndef TP1_NODE_H
#define TP1_NODE_H

template <typename T>
class Node
{
public:
	Node();

	T item;
	Node<T> *next = nullptr;
	Node<T> *previous = nullptr;
};

template <typename T>
Node<T>::Node()
{
	next = nullptr;
	previous = nullptr;
}

#endif // TP1_NODE_H
