#include "AlienDrones.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"

AlienDrones::AlienDrones(double h, int p, int ac, int t) :unit(h, p, ac, t)
{
	count = 0;
}

bool AlienDrones::enqueue(unit*& front, unit*& back)
{
	if (front)
	{
		count++;
		DoubleNode<unit*>* newNode = new DoubleNode<unit*>(front);
		newNode->setNext(frontPtr);
		frontPtr->setPrevious(newNode);
		frontPtr = frontPtr->getNext();
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
	if (isEmpty()) return false;
	DoubleQueue<unit*>::dequeue(beg);
	count--;
	if (!isEmpty())
	{
		end = backPtr->getItem();
		if (backPtr == frontPtr)
			frontPtr = NULL;       //special case if only one node exists 
		backPtr = backPtr->getPrevious();
		if (backPtr) {
			delete backPtr->getNext();
			backPtr->setNext(NULL);
		}
		count--;
	}
	else end = NULL;
	return true;
}


void AlienDrones::PrintAD()
{
	DoubleNode<unit*>* H = frontPtr;
	while (H)
	{
		H->getItem()->PrintUnit();
		std::cout << " ";
		H = H->getNext();
	}
}

int AlienDrones::getCount() { return count; }

int AlienDrones::attack(Game* GPtr)
{
	if (count < 2 || (GPtr->GetEArmy().GetET().isEmpty() && GPtr->GetEArmy().GetEG().isEmpty()))
		return false;
	unit* enemy;
	unit* attacker1 = frontPtr->getItem(), * attacker2 = backPtr->getItem();
	//to be contninued after better understanding of the logic
}
