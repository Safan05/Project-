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
	if (s->GetId() == -1) {
		s->SetId(id++);
	}
	return ESoldiers.enqueue(s);
 
}

bool EarthArmy::EnqueueETank(unit* t)
{
	if (t->GetId() == -1)
	t->SetId(id++);
	return ETanks.push(t);
}

bool EarthArmy::EnqueueEGunnery(unit* g)
{
	if (g->GetId() == -1)
	g->SetId(id++);
	return EGunnery.enqueue(g);
}
//bool EarthArmy::dequeES(unit*& s) {
//	return ESoldiers.Dequeue(s);
//}
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