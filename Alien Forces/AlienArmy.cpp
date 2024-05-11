#include "AlienArmy.h"
#include<iostream>
using namespace std;
AlienArmy::AlienArmy()
{
	id = 2000;
	AttackCount = 0;
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

void AlienArmy::IncAttackCount()
{
	AttackCount++;
}

int AlienArmy::GetAttackCount()
{
	return AttackCount;
}

void AlienArmy::Alienattack(Game* const& GPtr)
{
	unit* attacker = NULL, * attacker2 = NULL;
	if (AS.peek(attacker))
	{
		if(attacker->attack(GPtr))
			attacker->PrintAttacked();
	}
	if (AM.pick(attacker))
	{
		AM.setattacker(attacker);
		if(attacker->attack(GPtr))
			attacker->PrintAttacked();
	}
	if (AD.peek(attacker, attacker2))
	{
		if(attacker->attack(GPtr))
			attacker->PrintAttacked();
		if(attacker2->attack(GPtr))
			attacker2->PrintAttacked();
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

void AlienArmy::PrintAttack()
{
	unit* attacker = NULL, * attacker2 = NULL;
	if (AS.peek(attacker))
		attacker->PrintAttacked();
	attacker = AM.getAttacker();
	if (attacker)
		attacker->PrintAttacked();
	if (AD.peek(attacker, attacker2))
	{
		attacker->PrintAttacked();
		attacker2->PrintAttacked();
	}
}
