#include "EarthArmy.h"
#include<iostream>
using namespace std;
EarthArmy::EarthArmy(Game* g) //null ptr for now
{
	Gptr = g;
	Scount = 0;
	Tcount = 0;
	Gcount = 0;
	id = 0;
}

bool EarthArmy::EnqueueESoldier(unit* s)
{
	Scount++;
	s->SetId(id++);
	return ESoldiers.enqueue(s);
}

bool EarthArmy::EnqueueETank(unit* t)
{
	Tcount++;
	t->SetId(id++);
	return ETanks.push(t);
}

bool EarthArmy::EnqueueEGunnery(unit* g)
{
	Gcount++;
	g->SetId(id++);
	return EGunnery.PriorEnqueue(g);
}

LinkedQueue<unit*> EarthArmy::GetESoldiers()
{
	return LinkedQueue<unit*>(ESoldiers);
}

LinkedListStack<unit*> EarthArmy::GetETanks()
{
	return LinkedListStack<unit*>(ETanks);
}


LinkedQueue<unit*> EarthArmy::GetEGunnery()
{
	return LinkedQueue<unit*>(EGunnery);
}

void EarthArmy::PrintArmy()
{
	unit* temp;

	///////////////Printing ES List/////////////////
	LinkedQueue<unit*> EStemp;
	cout << Scount << " ES [";
	for (int i = 0; i < Scount; i++)
	{
		ESoldiers.dequeue(temp);
		temp->PrintUnit();
		if (i != Scount - 1)
			cout << ", ";
		EStemp.enqueue(temp);
	}
	cout << " ]";
	for (int i = 0; i < Scount; i++)
	{
		EStemp.dequeue(temp);
		ESoldiers.enqueue(temp);
	}

	///////////////Printing EG List/////////////////
	LinkedQueue<unit*> EGtemp;
	cout << Gcount << " EG [";
	for (int i = 0; i < Gcount; i++)
	{
		EGunnery.dequeue(temp);
		temp->PrintUnit();
		if (i != Gcount - 1)
			cout << ", ";
		EGtemp.enqueue(temp);
	}
	cout << " ]";
	for (int i = 0; i < Gcount; i++)
	{
		EGtemp.dequeue(temp);
		EGunnery.enqueue(temp);
	}
	//ETanks.PrintList(); only if operator overloading is allowed
}
