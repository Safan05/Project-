#include "AlliedArmy.h"
#include<iostream>

AlliedArmy::AlliedArmy()
{
	//saver units ids range between 4000 and 4999
	id = 4000;
	SUattacker = NULL;
}

bool AlliedArmy::AddUnit(unit*& u)
{
	if (id <= 4999)   //check for available ids
	{
		u->SetId(id++);
		SU.enqueue(u);
		return true;
	}
	return false;
}

SaverUnits& AlliedArmy::getSU()
{
	return SU;
}

void AlliedArmy::PrintArmy()
{
	std::cout << SU.Getcount() << " SU [";
	SU.PrintSU();
	std::cout << "]\n";
}

void AlliedArmy::SUattack(Game* const& Gptr)
{
	if (SU.peek(SUattacker))
		SUattacker->attack(Gptr);
	else SUattacker = NULL;     //in case saver units didn't attack at this time step
}

void AlliedArmy::printAttack()
{
	if (SUattacker)
	{
		SUattacker->PrintAttacked();
	}
}

void AlliedArmy::destroyArmy()
{
	unit* u = NULL;
	while (SU.dequeue(u))
		delete u;
}
