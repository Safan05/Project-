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

void AlienArmy::Alienattack(Game* const& GPtr)
{
	unit* attacker = NULL, * attacker2 = NULL;
	if (AS.peek(attacker))
		attacker->attack(GPtr);
	AM.pick(attacker);
	if(attacker)
	{
		AM.setattacker(attacker);
		attacker->attack(GPtr);
	}
	if (AD.peek(attacker, attacker2))
	{
		attacker->attack(GPtr);
		attacker2->attack(GPtr);
	}
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
