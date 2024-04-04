#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ESoldier : public unit
{
public:
	ESoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
	{
	}
	int attack(Game* GPtr)
	{
		int ESshots = 0;
		LinkedQueue<unit*> templist;
		unit* enemy = nullptr;
		for (int i = 0; i < unit::GetAC(); i++)
		{
			if (GPtr->GetAArmy().getAS().dequeue(enemy))
			{
				double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
				enemy->DecHealth(damage);
				ESshots++;
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
		return ESshots;
	}

};