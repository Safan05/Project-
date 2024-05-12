#pragma once
#include"SaverUnits.h"
#include"..\Unit\unit.h"
class Game;
class AlliedArmy
{
	SaverUnits SU;
	int id;
	int AttackCount;
public:
	AlliedArmy();
	bool AddUnit(unit*&);
	SaverUnits& getSU();
	int GetAttackCount();
	void PrintArmy();
	void SUattack(Game* const& Gptr);
	void printAttack();
	void distroyArmy();
};

