#include "AlienMonsters.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"


AlienMonsters::AlienMonsters(double h, int p, int ac, int t) :unit(h, p, ac, t)
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

bool AlienMonsters::attack(Game* GPtr) 
{
	if (count == 0 || (GPtr->GetEArmy().GetETanks().isEmpty() && GPtr->GetEArmy().GetESoldiers().isEmpty()))
		return false;
	LinkedListStack<unit*> Ttemp;
	LinkedQueue<unit*> Stemp;
	unit* attacker = monsters[rand() % count];
	unit* enemy;
	int ac = attacker->GetAC();

	//Attacking tanks with half attack capacity
	for (int i = 0; i < ac / 2; i++)
	{
		if (GPtr->GetEArmy().GetETanks().pop(enemy))
		{
			double damage = (attacker->GetPow() * attacker->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			if (enemy->is_killed())
				GPtr->EnqueueKilled(enemy);
			else Ttemp.push(enemy);
		}
	}
	while (Ttemp.pop(enemy))
		GPtr->GetEArmy().GetETanks().push(enemy);

	//Attacking soldiers with half attack capacity
	for (int i = ac / 2; i < ac; i++)
	{
		if (GPtr->GetEArmy().GetESoldiers().dequeue(enemy))
		{
			double damage = (attacker->GetPow() * attacker->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			if (enemy->is_killed())
				GPtr->EnqueueKilled(enemy);
			else Stemp.enqueue(enemy);
		}
	}
	while (Stemp.dequeue(enemy))
		GPtr->GetEArmy().GetESoldiers().enqueue(enemy);

	return true;
}