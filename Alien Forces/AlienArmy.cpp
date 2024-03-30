#include "AlienArmy.h"
#include<iostream>
using namespace std;
AlienArmy::AlienArmy(Game* g)
{
	Gptr = g;
	id = 1999;
}

bool AlienArmy::AddAS(unit* s)
{
	if (s->GetId() == -1)
	s->SetId(id++);
	return AS.enqueue(s);
}

bool AlienArmy::AddAM(unit* m)
{
	if (m->GetId() == -1)
	m->SetId(id++);
	return AM.AddAlienMonster(m);
}

bool AlienArmy::AddAD(unit* d)
{
	if (d->GetId() == -1)
	d->SetId(id++);
	return AD.enqueue(d);
}

int AlienArmy::getAlienCount()
{
	return AS.getCount() + AM.getCount() + AD.getCount();
}

AlienSoldiers AlienArmy::getAS() { return AS; }

AlienMonsters AlienArmy::getAM() { return AM; }

AlienDrones AlienArmy::getAD() { return AD; }

void AlienArmy::PrintArmy()
{
	///////////////Printing AS List/////////////////
	cout << AS.getCount() << " AS [";
	AS.PrintAS();
	cout << "]\n";
	///////////////Printing AM List/////////////////
	cout << AM.getCount() << " AM [";
	AM.PrintAM();
	cout << "]\n"; 
	///////////////Printing AD List/////////////////
	cout << AD.getCount() << " AD [";
	AD.PrintAD();
	cout << "]\n";
}
