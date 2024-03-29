#include "EarthArmy.h"
#include<iostream>
using namespace std;

EarthArmy::EarthArmy(Game* g) //null ptr for now
{
	Gptr = g;
	id = 0;
}

bool EarthArmy::EnqueueESoldier(unit* s)
{
	s->SetId(id++);
	return ESoldiers.Enqueue(s);
}

bool EarthArmy::EnqueueETank(unit* t)
{
	t->SetId(id++);
	return ETanks.Push(t);
}

bool EarthArmy::EnqueueEGunnery(unit* g)
{
	g->SetId(id++);
	return EGunnery.Enqueue(g);
}

EarthSoldiers EarthArmy::GetES()
{
	return EarthSoldiers(ESoldiers);
}

EarthGunnery EarthArmy::GetEG()
{
	return EarthGunnery(EGunnery);
}

EarthTank EarthArmy::GetET()
{
	return EarthTank(ETanks);
}

void EarthArmy::PrintArmy()
{
	///////////////Printing ES List/////////////////
	cout << ESoldiers.GetScount() << " ES [";
	ESoldiers.PrintES();
	cout << "]";
	cout << endl;

	///////////////Printing EG List/////////////////
	
	cout << EGunnery.GetGcount() << " EG [";
	EGunnery.PrintEG();
	cout << "]";
	cout << endl;
	///////////////Printing ET List/////////////////
	
	cout << ETanks.GetTcount() << " ET [";
	ETanks.PrintET();
	cout << "]";
	cout << endl;
}