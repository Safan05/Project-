#include "ESoldier.h"

ESoldier::ESoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ESoldier::attack(Game* const & GPtr)
{
	LinkedQueue<unit*> templist;
	unit* enemy = nullptr;
	for (int i = 0; i < unit::GetAC(); i++)
	{
		if (GPtr->GetAArmy().getAS().dequeue(enemy))
		{
			double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			if (!enemy->Wasattacked())
			{
				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
			}
			if (enemy->GetHealth() < 0)
				GPtr->EnqueueKilled(enemy);
			else
				templist.enqueue(enemy);
		}
	}
	while (templist.dequeue(enemy))
		GPtr->GetAArmy().getAS().enqueue(enemy);
	return true;
}