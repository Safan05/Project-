#include "AlienArmy.h"
#include<iostream>
using namespace std;
AlienArmy::AlienArmy()
{
	ASattacker = NULL; 
	AMattacker = NULL;
	ADattacker_1 = NULL; ADattacker_2 = NULL;
	id = 2000;
	AttackCount = 0;
}

bool AlienArmy::AddUnit(unit*& u)
{
	if (id <= 2999)
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
		default: break;
		}
		return true;
	}
	return false;
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
	//Alien soldiers attack
	if (AS.peek(ASattacker))
		ASattacker->attack(GPtr);
	else ASattacker = NULL;          //in case alien soldiers didn't attack at this time step
	//Alien monsters attack
	if (AM.pick(AMattacker))
		AMattacker->attack(GPtr);
	else AMattacker = NULL;         //in case alien monsters didn't attack at this time step
	//Alien drones attack
	if (AD.peek(ADattacker_1, ADattacker_2))
	{
		ADattacker_1->attack(GPtr);
		ADattacker_2->attack(GPtr);
	}
	else                            //in case alien drones didn't attack at this time step
	{
		ADattacker_1 = NULL;
		ADattacker_2 = NULL;
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
	if (ASattacker)
		ASattacker->PrintAttacked();
	if (AMattacker)
		AMattacker->PrintAttacked();
	if (ADattacker_1 && ADattacker_2)
	{
		ADattacker_1->PrintAttacked();
		ADattacker_2->PrintAttacked();
	}
}
