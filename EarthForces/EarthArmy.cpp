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
	LinkedQueue<unit*> EStemp(ESoldiers);
	int i = EunitsCount[0];
	cout << EunitsCount[0] << " ES [";
	while (EStemp.dequeue(temp))
	{
		temp->PrintUnit(); i--;
		if (i != 0)
			cout << ", ";
	}
	cout << "]";
	cout << endl;
	///////////////Printing EG List/////////////////
	LinkedQueue<unit*> EGtemp(EGunnery);
	i = EunitsCount[2];
	cout << EunitsCount[2] << " EG [";
	while (EGtemp.dequeue(temp))
	{
		temp->PrintUnit(); i--;
		if (i != 0)
			cout << ", ";
	}
	cout << "]";
	cout << endl;
	///////////////Printing ET List/////////////////
	LinkedListStack<unit*> ETtemp;
	while (ETanks.pop(temp))
		ETtemp.push(temp);
	i = EunitsCount[1];
	cout << EunitsCount[1] << " ET [";
	while (ETtemp.pop(temp))
	{
		temp->PrintUnit();
		ETanks.push(temp); i--;
		if (i != 0)
			cout << ", ";
	}
	cout << "]";
	cout << endl;
}

int* EarthArmy::GetEcount()
{
	return EunitsCount;
}
