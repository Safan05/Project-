#include "EarthSoldiers.h"
#include"../Unit/ESoldier.h"
#include<cmath>
#include"..\Game\Game.h"
EarthSoldiers::EarthSoldiers()
{
	Scount = 0;
	InfectedES = nullptr;
}

bool EarthSoldiers::enqueue(unit*& s)
{
	if (LinkedQueue<unit*>::enqueue(s))
	{
		ESoldier* e = dynamic_cast<ESoldier*>(s);
		if (e->IsInfected())
			InfCount++;
		Scount++;
		return true;
	}
	return false;
}

bool EarthSoldiers::dequeue(unit*& s)
{
	if(	LinkedQueue<unit*>::dequeue(s))
	{
		ESoldier* e = dynamic_cast<ESoldier*>(s);
		if (e->IsInfected())
			InfCount--;
		Scount--; 
		return true;
	}
	return false;
}

bool EarthSoldiers::Infect(int z)
{
	Node<unit*>* ptr = frontPtr;
	for (int i = 0; i < z; i++)
	{
		if(ptr)
			ptr = ptr->getNext();
	}
	if (ptr)
	{
		ESoldier* e = dynamic_cast<ESoldier*>(ptr->getItem());
		if (e->IsInfected() || e->isImmune())
			return false;
		else
		{
			e->SetInfected(true);
			InfCount++;
			return true;
		}
	}
	return false;
}

int EarthSoldiers::GetScount()
{
	return Scount;
}

int EarthSoldiers::GetInfCount()
{
	return InfCount;
}
unit*& EarthSoldiers::GetInfected()
{
	return InfectedES;
}


void EarthSoldiers::PrintES()
{
	Node<unit*>* temp = frontPtr;
	if (InfectedES)
		InfectedES->PrintUnit();
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


