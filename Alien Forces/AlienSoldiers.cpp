#include "AlienSoldiers.h"
#include<iostream>
#include<cmath>
#include"..\Game\Game.h"

AlienSoldiers::AlienSoldiers(double h, int p, int ac, int t) :unit(h, p, ac, t)
{
	count = 0;
}

bool AlienSoldiers::enqueue(unit* s)
{
	count++;
	return LinkedQueue<unit*>::enqueue(s);
}

bool AlienSoldiers::dequeue(unit* s)
{
	if (LinkedQueue<unit*>::dequeue(s))
	{
		count--;
		return true;
	}
	return false;
}

void AlienSoldiers::PrintAS()
{
	Node<unit*>* H = frontPtr;
	while (H)
	{
		H->getItem()->PrintUnit();
		std::cout << " ";
		H = H->getNext();
	}
}

int AlienSoldiers::getCount() {	return count; }

bool AlienSoldiers::attack(Game* GPtr)
{
	if (!frontPtr || GPtr->GetEArmy().GetES().isEmpty())
		return false;
	unit* enemy;
	unit* attacker = frontPtr->getItem();
	LinkedQueue<unit*> temp;
	for (int i = 0; i < attacker->GetAC(); i++)
	{
		if (GPtr->GetEArmy().GetES().dequeue(enemy))
		{
			double damage = (attacker->GetPow() * attacker->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			if (enemy->is_killed())
				GPtr->EnqueueKilled(enemy);
			else temp.enqueue(enemy);
		}
	}
	while (temp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);
	return true;
}
