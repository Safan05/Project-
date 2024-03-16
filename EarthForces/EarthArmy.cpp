#include "EarthArmy.h"
#include<iostream>
using namespace std;
EarthArmy::EarthArmy(Game* g) //null ptr for now
{
	for (int i = 0; i < 3; i++)
		EunitsCount[i] = 0;
	Gptr = g;
	id = 0;
}

bool EarthArmy::EnqueueESoldier(unit* s)
{
	EunitsCount[0]++;
	s->SetId(id++);
	return ESoldiers.enqueue(s);
}

bool EarthArmy::EnqueueETank(unit* t)
{
	EunitsCount[1]++;
	t->SetId(id++);
	return ETanks.push(t);
}

bool EarthArmy::EnqueueEGunnery(unit* g)
{
	EunitsCount[2]++;
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
	cout << EunitsCount[0] << " ES [";
	for (int i = 0; i < EunitsCount[0]; i++)
	{
		ESoldiers.dequeue(temp);
		temp->PrintUnit();
		if (i != EunitsCount[0] - 1)
			cout << ", ";
		EStemp.enqueue(temp);
	}
	cout << "]";
	for (int i = 0; i < EunitsCount[0]; i++)
	{
		EStemp.dequeue(temp);
		ESoldiers.enqueue(temp);
	}

	///////////////Printing EG List/////////////////
	LinkedQueue<unit*> EGtemp;
	cout << EunitsCount[2] << " EG [";
	for (int i = 0; i < EunitsCount[2]; i++)
	{
		EGunnery.dequeue(temp);
		temp->PrintUnit();
		if (i != EunitsCount[2] - 1)
			cout << ", ";
		EGtemp.enqueue(temp);
	}
	cout << "]";
	for (int i = 0; i < EunitsCount[2]; i++)
	{
		EGtemp.dequeue(temp);
		EGunnery.enqueue(temp);
	}
	//ETanks.PrintList(); only if operator overloading is allowed
}

int* EarthArmy::GetEcount()
{
	return EunitsCount;
}
