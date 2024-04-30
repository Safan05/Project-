#include "HealUnits.h"
#include "..\Game\Game.h"
HealUnits::HealUnits()
{
	HUCount = 0;
}

bool HealUnits::push(unit*& t)
{
	HUCount++;
	return LinkedListStack<unit*>::push(t);
}

bool HealUnits::pop(unit*& t)
{
	if (LinkedListStack<unit*>::pop(t))
	{
		HUCount--; return true;
	}
	return false;
}

int HealUnits::GetHUcount()
{
	return HUCount;
}

void HealUnits::PrintHU()
{
	Node<unit*>* temp = head;
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())       //Printing style fix
			cout << ", ";
		temp = temp->getNext();
	}
}

HealUnits::~HealUnits()
{
	unit* temp = nullptr;
	while (this->pop(temp))
	{
		delete temp;
	}
}
