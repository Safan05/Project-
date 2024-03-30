#pragma once
#include"..\unit.h"
class AlienMonsters:public unit
{
	int count;
	unit* monsters[1000];
public:
	AlienMonsters(double h = 0, int p = 0, int ac = 0, int t = 0);
	bool AddAlienMonster(unit*);
	bool removeAlienMonster(unit*&);
	void PrintAM();
	int getCount();
	bool attack(Game* GPtr);
};