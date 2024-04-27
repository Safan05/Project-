#include "AlienArmy.h"
#include<iostream>
using namespace std;
AlienArmy::AlienArmy(Game* g)
{
	Gptr = g;
	id = 2000;
}

bool AlienArmy::AddUnit(unit* u)
{
	u->SetId(id++);
	switch (u->GetType())
	{
	case aliensoldier:
		return AS.enqueue(u);
	case monster:
		return AM.AddAlienMonster(u);
	case drone:
	{ 
		unit* ptr = NULL;
		return AD.enqueue(ptr, u);
	}
	default: return false;
	}
}

int AlienArmy::getAlienCount()
{
	return AS.getCount() + AM.getCount() + AD.getCount();
}

bool AlienArmy::Alienattack(Game* const& GPtr)
{
	bool a1 = AS.ASattack(GPtr);
	bool a2 = AM.AMattack(GPtr);
	bool a3 = AD.ADattack(GPtr);
	return (a1 || a2 || a3);
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
