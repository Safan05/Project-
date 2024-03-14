
#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include "NodeP.h"
#include "QueueADT.h"
#include <vector>
using namespace std;


template <typename T, typename P>
class LinkedQueue :public QueueADT<T>
{
protected:

	Node<T,P>* backPtr;
	Node<T,P>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedQueue();

	//copy constructor
	LinkedQueue(const LinkedQueue<T,P>& LQ);
};

template <typename T, typename P>
LinkedQueue<T,P>::LinkedQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template <typename T,typename P>
bool LinkedQueue<T,P>::isEmpty() const
{
	return (frontPtr == nullptr);
}


template <typename T, typename P>
bool LinkedQueue<T,P>::enqueue(const T& newEntry)
{
	Node<T, P>* newNodePtr = new Node<T,P>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		frontPtr = newNodePtr; // The queue is empty
	else
		backPtr->setNext(newNodePtr); // The queue was not empty

	backPtr = newNodePtr; // New node is the last node now
	return true;
} 


template <typename T, typename P>
bool LinkedQueue<T,P>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T,P>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;

	return true;

}

template <typename T,typename P>
bool LinkedQueue<T,P>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T,typename P>
LinkedQueue<T,P>::~LinkedQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

template <typename T, typename P>
LinkedQueue<T,P>::LinkedQueue(const LinkedQueue<T,P>& LQ)
{
	Node<T, P>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Node<T, P>* ptr = new Node<T, P>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		Node<T, P>* ptr = new Node<T, P>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}

#endif
