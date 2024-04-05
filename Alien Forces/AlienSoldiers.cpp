#include "AlienSoldiers.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"

AlienSoldiers::AlienSoldiers()
{
	count = 0;
	shots = 0;
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
	Node<unit*>* H = frontPtr;
	while (H)
	{
		H->getItem()->PrintUnit();
		std::cout << " ";
		H = H->getNext();
	}
}

int AlienSoldiers::getCount() { return count; }

AlienSoldiers::~AlienSoldiers()
{
	unit* temp = NULL;
	while (dequeue(temp))
		delete temp;
}
