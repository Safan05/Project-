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
	case aliensoldier:          //if the new unit is Alien soldier ,add it to AS list
		return AS.enqueue(u);
	case monster:              //if the new unit is Alien monster ,add it to AM list
		return AM.AddAlienMonster(u);
	case drone:                //if the new unit is Alien Drone ,add it to AD list
	{ 
		unit* ptr = NULL;     //a new drone is enqueued at the end of the list ,but during attack drones are enqueued at the front and the back
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
	//Alien soldiers attack
	if (AS.peek(attacker))
		attacker->attack(GPtr); 
	//Alien monsters attack
	if (AM.pick(attacker))  
	{
		AM.setattacker(attacker);   //since monsters attack randomly ,we need to know which monster made the attack 
		attacker->attack(GPtr);
	}
	//Alien drones attack
	if (AD.peek(attacker, attacker2))
	{
		attacker->attack(GPtr);
		attacker2->attack(GPtr);
	}
}

void AlienArmy::PrintAttack()
{
	unit* attacker = NULL, * attacker2 = NULL;
	//printing units attack by alien soldier
	if (AS.peek(attacker))
		attacker->PrintAttacked();
	//printing units attacked by alien monster
	attacker = AM.getAttacker();   //since monsters attack randomly ,we need to get the monster which made the attack 
	if (attacker)
		attacker->PrintAttacked();
	//printing units attacked by alien drones
	if (AD.peek(attacker, attacker2))
	{
		attacker->PrintAttacked();   //units attacked by the front drone
		attacker2->PrintAttacked();  //units attacked by the back drone
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
