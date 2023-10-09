#include "Node.h"

#ifndef TP1_PILHA_H
#define TP1_PILHA_H

template <typename T>
class Stack
{
public:
	Stack();
    ~Stack();
	void push(T item);
	T pop();
	bool isEmpty();
	void print();
    void printInverse();
	int size = 0;
    // GPT
    Stack(const Stack& other);

private:
	Node<T> *first;
	Node<T> *last;
};

//GPT
template <typename T>
Stack<T>::Stack(const Stack& other) {
    first = new Node<T>();
    first->next = last;
    first->previous = first;
    last = first;

    Node<T>* temp = other.first;
    while (temp != nullptr) {
        push(temp->item);
        temp = temp->next;
    }
}

//MEu
template <typename T>
Stack<T>::Stack()
{
    first = new Node<T>();
    first->next = last;
    first->previous = first;
    last = first;
}


template<typename T>
Stack<T>::~Stack() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
    }
}

template<typename T>
void Stack<T>::printInverse() {
    auto *temp = new Node<T>;
    temp = last;
    for (int i = 0; i < size; ++i)
    {
        cout << temp->item << " ";
        temp = temp->previous;
    }
    cout << endl;
    temp = nullptr;
    delete temp;
}

template <typename T>
void Stack<T>::print()
{
	auto *temp = new Node<T>;
	temp = first;
	for (int i = 0; i < size; ++i)
	{
		cout << temp->item << " ";
		temp = temp->next;
	}
	cout << endl;
    temp = nullptr;
    delete temp;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		return T();
	}
	T valorlast = last->item;
	Node<T> *temp = last;
	last = last->previous;
	last->next = nullptr;
	size--;
	return valorlast;
}

template <typename T>
void Stack<T>::push(T item)
{

	if (size == 0)
	{
		first->item = item;
		size++;
		return;
	}
	auto *temp = new Node<T>();
	temp->item = item;
	temp->previous = last;
	last->next = temp;
	last = temp;
	size++;
}


#endif // TP1_PILHA_H
