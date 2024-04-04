#include "EarthTanks.h"
#include"../Game/Game.h"
EarthTanks::EarthTanks()
{
	ETshots = 0;
	Tcount = 0;
	ESbelow80 = false;
}

bool EarthTanks::push(unit*& t)
{
	Tcount++;
	return LinkedListStack<unit*>::push(t);
}

bool EarthTanks::pop(unit*& t)
{
	if (LinkedListStack<unit*>::pop(t))
	{
		Tcount--; return true;
	}
	return false;
}

bool EarthTanks::ETattack(Game* Gptr)
{
	if (head)
	{
		ETshots += head->getItem()->attack(Gptr);
		return true;
	}
	return false;
}

int EarthTanks::GetTcount()
{
	return Tcount;
}

void EarthTanks::PrintET()
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
