#ifndef LinkedStack
#define LinkedStack
#include"StackADT.h"
#include"Node.h"
#include<iostream>
using namespace std;

template <typename t>
class LinkedListStack :public StackADT<t>
{
protected:
	Node<t>* head;
public:
	LinkedListStack()
	{
		head = nullptr;
	}
	bool isEmpty() const
	{
		return head == nullptr;
	}
	bool push(const t& newEntry)
	{
		if (!head)
			head = new Node<t>(newEntry);
		else
		{
			Node<t>* r = new Node<t>(newEntry);
			r->setNext(head);
			head = r;
		}
		return true;
	}
	bool pop(t& TopEntry)
	{
		if (isEmpty())
			return false;
		Node<t>* r = head;
		head = head->getNext();
		TopEntry = r->getItem();
		delete r;
		return true;
	}
	bool peek(t& TopEntry) const
	{
		if (isEmpty())
			return false;
		TopEntry = head->getItem();
		return true;
	}
	void PrintList()
	{
		Node<t>* ptr = head;
		while (ptr)
		{
			cout << ptr->getItem() << " -> ";
			ptr = ptr->getNext();
		}
		cout << "Null\n";
	}
	~LinkedListStack()
	{
		t item;
		while (pop(item));
	}
};
#endif
