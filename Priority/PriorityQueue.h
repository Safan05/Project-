#ifndef _Prior_
#define _Prior_
#include"LinkedQueue.h"
template <typename T,typename P>

class PriorityQueue :public LinkedQueue<T,P>
{
public:
	bool enqueue(const T& newEntry,P p)
	{
		bool inside = false;
		Node<T,P>* newNodePtr = new Node<T,P>(newEntry,p);
		if (this->isEmpty())
		{
			frontPtr = newNodePtr;
			inside = true;
		}
		else
		{
			Node<T, P>* ptr = frontPtr;
			if (ptr->getPrior() < p)
			{
				newNodePtr->setNext(frontPtr);
				frontPtr = newNodePtr;
				inside = true;
			}
			else
			while (ptr->getNext() && !inside)
			{
				if (ptr->getNext()->getPrior() < p)
				{
					newNodePtr->setNext(ptr->getNext());
					ptr->setNext(newNodePtr);
					inside = true;
				}
				ptr = ptr->getNext();
			}
			if (!inside)
			{
				ptr->setNext(newNodePtr);
			}
		}
		return true;
	}
};
#endif 

