#include "AlienSoldiers.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"

AlienSoldiers::AlienSoldiers()
{
	count = 0;
}

bool AlienSoldiers::enqueue(unit*& s)
{
	count++;
	return LinkedQueue<unit*>::enqueue(s);
}

bool AlienSoldiers::dequeue(unit*& s)
{
	if (LinkedQueue<unit*>::dequeue(s))
	{
		count--;
		return true;
	}
	return false;
}

void AlienSoldiers::PrintAS()
{
	Node<unit*>* temp = frontPtr;
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())       
			cout << ", ";
		temp = temp->getNext();
	}
}

int AlienSoldiers::getCount() { return count; }

AlienSoldiers::~AlienSoldiers()
{
	unit* temp = nullptr;
	while (this->dequeue(temp))
		delete temp;
	temp = nullptr;
}
