#include "EarthSoldiers.h"
#include<cmath>
EarthSoldiers::EarthSoldiers(int H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool EarthSoldiers::attack(Game* GPtr)
{
	LinkedQueue<unit*>templist;
	unit* enemy;
	for (int i = 0; i < unit::GetAC(); i++)
	{
		GPtr->GetEArmy().GetESoldiers().dequeue(enemy);
		double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
		enemy->DecHealth(damage);
		if (enemy->GetHealth() < 0)
		{
			GPtr->EnqueueKilled(enemy);
		}
		else {
			templist.enqueue(enemy);
		}
	}
	while (GPtr->GetEArmy().GetESoldiers().dequeue(enemy))
		templist.enqueue(enemy);
	while (templist.dequeue(enemy))
		GPtr->GetEArmy().GetESoldiers().enqueue(enemy);
	return true;
}


