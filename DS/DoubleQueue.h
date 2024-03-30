#pragma once

#include"DoubleNode.h"
#include "QueueADT.h"

template <typename T>
class DoubleQueue :public QueueADT<T>
{
protected:
	DoubleNode<T>* backPtr;
	DoubleNode<T>* frontPtr;
public:
	DoubleQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~DoubleQueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
DoubleQueue<T>::DoubleQueue()
{
	backPtr = NULL;
	frontPtr = NULL;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool DoubleQueue<T>::isEmpty() const
{
	return (frontPtr == NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::enqueue(const T& newEntry)
{
	DoubleNode<T>* newDoubleNodePtr = new DoubleNode<T>(newEntry);
	// Insert the new DoubleNode
	if (isEmpty())	//special case if this is the first DoubleNode to insert
		frontPtr = newDoubleNodePtr; // The queue is empty
	else
	{
		backPtr->setNext(newDoubleNodePtr); // The queue was not empty
		newDoubleNodePtr->setPrevious(backPtr);
	}
	backPtr = newDoubleNodePtr; // New DoubleNode is the last DoubleNode now
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool DoubleQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	DoubleNode<T>* DoubleNodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (DoubleNodeToDeletePtr == backPtr)	 // Special case: last DoubleNode in the queue
		backPtr = NULL;

	// Free memory reserved for the dequeued DoubleNode
	delete DoubleNodeToDeletePtr;
	if (frontPtr)
		frontPtr->setPrevious(NULL);
	return true;
}



/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/

template <typename T>
bool DoubleQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
DoubleQueue<T>::~DoubleQueue()
{
	T temp;
	while (dequeue(temp));
}