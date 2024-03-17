#include "AlienArmy.h"
#include<iostream>

AlienArmy::AlienArmy(Game* g)
{
	Gptr = g;
	id = 1999;
}

bool AlienArmy::AddAS(unit* s)
{
	s->SetId(id++);
	return AS.enqueue(s);
}

bool AlienArmy::AddAM(unit* m)
{
	m->SetId(id++);
	return AM.AddAlienMonster(m);
}

bool AlienArmy::AddAD(unit* d)
{
	d->SetId(id++);
	return AD.enqueue(d);
}

int AlienArmy::getAlienCount()
{
	return AS.getCount() + AM.getCount() + AD.getCount();
}

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
