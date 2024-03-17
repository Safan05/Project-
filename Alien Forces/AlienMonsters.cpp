#include "AlienMonsters.h"
#include<iostream>

AlienMonsters::AlienMonsters(double h, int p, int ac, int t) :unit(h, p, ac, t)
{
	count = 0;
	monsters = new unit * [1];
}

bool AlienMonsters::AddAlienMonster(unit* m)
{
	count++;
	unit** temp = monsters;
	monsters = new unit * [count];
	for (int i = 0; i < count - 1; i++)
		monsters[i] = temp[i];
	monsters[count-1] = m;
	delete temp;
	return true;
}

bool AlienMonsters::removeAlienMonster(unit* m)
{
	if (count < 1) return false;
	int i = rand() % count;
	std::swap(monsters[i], monsters[count - 1]);
	m = monsters[count - 1];
	count--;
	return true;
}

void AlienMonsters::PrintAM()
{
	for (int i = 0; i < count; i++)
	{
		monsters[i]->PrintUnit();
		std::cout << " ";
	}
}

int AlienMonsters::getCount() {	return count; }

bool AlienMonsters::attack(Game* GPtr){	return false; }

AlienMonsters::~AlienMonsters()
{
	delete monsters;
}
