#include "AlienDrones.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"

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
	if (!LinkedQueue<unit*>::dequeue(beg))
		return false;
	count--;
	if (!frontPtr->getNext())
		end = nullptr;
	else
	{
		Node<unit*>* E = frontPtr;
		while (E->getNext()->getNext())
			E = E->getNext();
		backPtr = E;
		end = E->getNext()->getItem();
		delete E->getNext();
		count--;
	}
	return true;
}


void AlienDrones::PrintAD()
{
	Node<unit*>* H = frontPtr;
	while (H)
	{
		H->getItem()->PrintUnit();
		std::cout << " ";
		H = H->getNext();
	}
}

int AlienDrones::getCount() { return count; }

bool AlienDrones::attack(Game* GPtr)
{
	if (count < 2 || (GPtr->GetEArmy().GetETanks().isEmpty() && GPtr->GetEArmy().GetEGunnery().isEmpty()))
		return false;
	unit* enemy;
	unit* attacker1 = frontPtr->getItem(), * attacker2 = backPtr->getItem();
	//to be contninued after better understanding of the logic
}
