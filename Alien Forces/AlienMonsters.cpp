#include "AlienMonsters.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"


AlienMonsters::AlienMonsters()
{
	count = 0;
	for (int i = 0; i < 1000; i++)
		monsters[i] = nullptr;
}

bool AlienMonsters::AddAlienMonster(unit* m)
{
	if (count == 1000) return false;
	monsters[count] = m;
	count++;
	return true;
}

bool AlienMonsters::removeAlienMonster(unit*& m)
{
	if (count < 1) return false;
	int i = rand() % count;
	unit* temp = monsters[i];
	monsters[i] = monsters[count - 1];
	monsters[count - 1] = temp;
	m = monsters[count - 1];
	count--;
	return true;
}

void AlienMonsters::PrintAM()
{
	int i;
	for (i = 0; i < count - 2; i++)
	{
		monsters[i]->PrintUnit();
		std::cout << ", ";
	}
	if (monsters[i])
		monsters[i]->PrintUnit();
}

int AlienMonsters::getCount() { return count; }

bool AlienMonsters::AMattack(Game* const& GPtr)
{
	if (count == 0)
		return false;
	else
	{
		int i = rand() % count;
		bool m = monsters[i]->attack(GPtr);
		monsters[i]->PrintAttacked();
		return m;
	}
}

AlienMonsters::~AlienMonsters()
{
	for (int i = 0; i < count; i++)
		if (monsters[i])
			delete monsters[i];
}
