#include "SaverUnits.h"
#include"..\Game\Game.h"

SaverUnits::SaverUnits() { count = 0; }

bool SaverUnits::enqueue(unit*& u)
{
	count++;
	return LinkedQueue<unit*>::enqueue(u);
}

bool SaverUnits::dequeue(unit*& u)
{
	if (LinkedQueue<unit*>::dequeue(u))
	{
		count--;
		return true;
	}
	return false;
}

int SaverUnits::Getcount(){	return count;}

void SaverUnits::PrintSU()
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

SaverUnits::~SaverUnits()
{
	unit* temp = nullptr;
	while (this->dequeue(temp))
	{
		delete temp;
	}
}
