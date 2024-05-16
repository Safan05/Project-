#include "AlienArmy.h"
#include"..\Unit\AMonster.h"
#include<iostream>
using namespace std;
AlienArmy::AlienArmy()
{
	ASattacker = NULL; 
	AMattacker = NULL;
	ADattacker_1 = NULL; ADattacker_2 = NULL;
	id = 2000;         //alien ids range between 2000 and 2999
	AttackCount = 0;
}

bool AlienArmy::AddUnit(unit*& u)
{
	if (id <= 2999)       //check for available ids
	{
		u->SetId(id++);
		switch (u->GetType())
		{
		case aliensoldier:            //if the new unit is Alien soldier ,add it to AS list
			return AS.enqueue(u);
		case monster:                 //if the new unit is Alien monster ,add it to AM list 
			return AM.AddAlienMonster(u);
		case drone:                   //if the new unit is Alien Drone ,add it to AD list
		{
			//a new drone is enqueued at the end of the list ,but during attack drones are enqueued and dequeued at the front and the back (one fresh and one old drone)
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
	//print units attacked by alien soldier at current time step 
	if (ASattacker)
		ASattacker->PrintAttacked();
	//print units attacked or infected by alien monster at current time step 
	if (AMattacker)
	{
		AMattacker->PrintAttacked();
		AMonster* am = dynamic_cast<AMonster*>(AMattacker);
		am->PrintInfected();
	}
	//print units attacked by alien drones at current time step 
	if (ADattacker_1 && ADattacker_2)
	{
		ADattacker_1->PrintAttacked();        //units attacked by the front drone (oldest drone)   
		ADattacker_2->PrintAttacked();        //units attacked by the back drone  (freshest drone)
	}
}
