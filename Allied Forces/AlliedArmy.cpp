#include "AlliedArmy.h"
#include<iostream>

AlliedArmy::AlliedArmy()
{
	id = 4000;
	AttackCount = 0;
}

bool AlliedArmy::AddUnit(unit*& u)
{
	if (id <= 4999)
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

int AlliedArmy::GetAttackCount()
{
	return AttackCount;
}

void AlliedArmy::PrintArmy()
{
	std::cout << SU.Getcount() << " ES [";
	SU.PrintSU();
	std::cout << "]\n";
}

void AlliedArmy::SUattack(Game* const& Gptr)
{
	unit* u = NULL;
	if (SU.peek(u))
		u->attack(Gptr);
}

void AlliedArmy::printAttack()
{
	unit* u = NULL;
	if (SU.peek(u))
		u->PrintAttacked();
}
