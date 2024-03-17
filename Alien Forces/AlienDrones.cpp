#include "AlienDrones.h"
#include<iostream>

AlienDrones::AlienDrones(double h, int p, int ac, int t) :unit(h, p, ac, t)
{
	count = 0;
}

bool AlienDrones::enqueue(unit* s)
{
	count++;
	return LinkedQueue<unit*>::enqueue(s);
}

bool AlienDrones::deque(unit* beg, unit* end)
{
	if (count < 2) return false;
	LinkedQueue::dequeue(beg);
	Node<unit*>* E = frontPtr;

	while (E->getNext()->getNext())
			E = E->getNext();
	backPtr = E;
	end = E->getNext()->getItem();
	return true;
}


void AlienDrones::PrintAD()
{
	LinkedQueue<unit*> temp(*this);
	unit* ad;
	while (temp.dequeue(ad))
	{
		ad->PrintUnit();
		std::cout << " ";
	}
}

int AlienDrones::getCount() { return count; }

bool AlienDrones::attack(Game* GPtr) { return false; }
