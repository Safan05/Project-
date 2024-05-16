#include "AlienMonsters.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"


AlienMonsters::AlienMonsters()
{
	// array initially empty 
	count = 0;
	for (int i = 0; i < 1000; i++)
		monsters[i] = nullptr;
}

bool AlienMonsters::pick(unit*& mon)
{
	if (count < 1)
		return false;
	int i = rand() % count;      //generate a random index between zero and the number of monsters in the array
	mon = monsters[i];
	return true;
}

bool AlienMonsters::AddAlienMonster(unit* m)
{
	if (count == 1000)
		return false;
	monsters[count] = m;
	count++;
	return true;
}

bool AlienMonsters::removeAlienMonster(unit*& m)
{
	if (count < 1) 
		return false;
	int i = rand() % count;       //generate a random index between zero and the number of monsters in the array
	m = monsters[i];
	//swap the element to be removed with the last element in the array
	unit* temp = monsters[count-1];
	monsters[count-1] = monsters[i];
	monsters[i] = temp;
	monsters[count - 1] = NULL;     //make the last element point to null
	count--;                        //then decrease the count
	return true;
}

void AlienMonsters::PrintAM()
{
	int i;
	for (i = 0; i < count - 1; i++)
	{
		monsters[i]->PrintUnit();
		std::cout << ", ";
	}
	if(monsters[i])
		monsters[i]->PrintUnit();
}

int AlienMonsters::getCount() { return count; }

bool AlienMonsters::isEmpty()
{
	return (count == 0);
}

AlienMonsters::~AlienMonsters()
{
	for (int i = 0; i < count - 1; i++)
		delete monsters[i];
}
