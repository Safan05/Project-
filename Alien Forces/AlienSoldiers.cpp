#include "AlienSoldiers.h"
#include<iostream>

AlienSoldiers::AlienSoldiers(double h, int p, int ac, int t) :unit(h, p, ac, t)
{
	count = 0;
}

bool AlienSoldiers::enqueue(unit* s)
{
	count++;
	return LinkedQueue<unit*>::enqueue(s);
}

void AlienSoldiers::PrintAS()
{
	LinkedQueue<unit*> temp(*this);
	unit* as;
	while (temp.dequeue(as))
	{
		as->PrintUnit();
		std::cout << " ";
	}
}

int AlienSoldiers::getCount() {	return count; }

bool AlienSoldiers::attack(Game* GPtr) { return false; }
