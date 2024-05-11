#include "EarthSoldiers.h"
#include<cmath>
#include"..\Game\Game.h"
EarthSoldiers::EarthSoldiers()
{
	Scount = 0;
}

bool EarthSoldiers::enqueue(unit*& s)
{
	Scount++;
	return LinkedQueue<unit*>::enqueue(s);
}

bool EarthSoldiers::dequeue(unit*& s)
{
	if (LinkedQueue<unit*>::dequeue(s))
	{
		Scount--; return true;
	}
	return false;
}

bool EarthSoldiers::InfEnqueue(unit*& v)
{
	if (InfectedES.enqueue(v))
	{
		InfCount++; return true;
	}
	return false;
}

bool EarthSoldiers::InfDequeue(unit*& v)
{
	if (InfectedES.dequeue(v))
	{
		InfCount--; return true;
	}
	return false;
}

int EarthSoldiers::GetScount()
{
	return Scount;
}

LinkedQueue<unit*> EarthSoldiers::GetInfected()
{
	return LinkedQueue<unit*>(InfectedES);
}


void EarthSoldiers::PrintES()
{
	Node<unit*>* temp = frontPtr;
	while (temp)
	{
		temp->getItem()->PrintUnit();
		if (temp->getNext())        //Printing style fix
			cout << ", ";
		temp = temp->getNext();
	}
}

EarthSoldiers::~EarthSoldiers()
{
	unit* temp = nullptr;
	while (this->dequeue(temp))
	{
		delete temp;
	}
}


