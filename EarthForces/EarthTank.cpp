#include "EarthTank.h"
EarthTank::EarthTank(double H, int P, int AC, int T) : unit(H, P, AC, T)
{
	Tcount = 0;
}

bool EarthTank::push(unit* t)
{
	Tcount++;
	return LinkedListStack<unit*>::push(t);
}

bool EarthTank::pop(unit* t)
{
	Tcount--;
	return LinkedListStack<unit*>::pop(t);
}

bool EarthTank::attack(Game* ptr)
{
	return false;
}

int EarthTank::GetTcount()
{
	return Tcount;
}

void EarthTank::PrintET()
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
