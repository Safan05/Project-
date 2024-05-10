#include "AlienDrones.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"

AlienDrones::AlienDrones()
{
	count = 0;
}

bool AlienDrones::enqueue(unit*& front, unit*& back)
{
	if (front)       //not to enqueue null pointers     
	{
		count++;
		DoubleNode<unit*>* newNode = new DoubleNode<unit*>(front);
		if (frontPtr)   
		{
			newNode->setNext(frontPtr);
			frontPtr->setPrevious(newNode);
			frontPtr = frontPtr->getNext();
		}
		else frontPtr = newNode;  //special case: the list was empty
	}
	if (back)
	{
		count++;
		DoubleQueue<unit*>::enqueue(back);
	}
	return true;
}

bool AlienDrones::dequeue(unit*& beg, unit*& end)
{
	if (isEmpty()) 
		return false;
	DoubleQueue<unit*>::dequeue(beg);   //dequeue the front pointer
	count--;
	if (!isEmpty())  //dequeue the back pointer if it exists  
	{
		end = backPtr->getItem();
		if (backPtr == frontPtr)
			frontPtr = NULL;       //special case if only one node exists 
		backPtr = backPtr->getPrevious();
		if (backPtr)
		{
			delete backPtr->getNext();
			backPtr->setNext(NULL);
		}
		count--;
	}
	else end = NULL;
	return true;
}

bool AlienDrones::peek(unit*& beg, unit*& end)
{
	if (count < 2)
		return false;
	DoubleQueue<unit*>::peek(beg);
	end = backPtr->getItem();
	return true;
}


void AlienDrones::PrintAD()
{
	DoubleNode<unit*>* H = frontPtr;
	while (H)
	{
		H->getItem()->PrintUnit();
		if (H->getNext())
			std::cout << ", ";
		H = H->getNext();
	}
}

int AlienDrones::getCount() { return count; }

AlienDrones::~AlienDrones()
{
	unit* temp1 = NULL, *temp2 = NULL;
	while (dequeue(temp1, temp2))
	{
		if(temp1) delete temp1;
		if (temp2)delete temp2;
	}
}
