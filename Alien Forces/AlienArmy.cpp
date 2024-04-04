#include "AlienArmy.h"
#include "../Game/Game.cpp"
#include<iostream>
using namespace std;
AlienArmy::AlienArmy(Game* g)
{
	Gptr = g;
	id = 2000;
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
	unit* temp = NULL;          //Adds the new drone at the end of the Doublequeue ,edit if needed
	return AD.enqueue(temp, d);
}

int AlienArmy::getAlienCount()
{
	return AS.getCount() + AM.getCount() + AD.getCount();
}

AlienSoldiers& AlienArmy::getAS() { return AS; }

AlienMonsters& AlienArmy::getAM() { return AM; }

AlienDrones& AlienArmy::getAD() { return AD; }

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
