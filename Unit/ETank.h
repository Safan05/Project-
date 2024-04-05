#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ETank :public unit
{
	bool ESbelow80;
public:
	ETank(double H, int P, int AC, int T) :unit(H, P, AC, T)
	{
		ESbelow80 = false;
	}
	int attack(Game* Gptr)
	{
		int ETshots = 0;
		LinkedListStack<unit*> templist;           //any DS for templist of monsters is valid  
		unit* enemy = nullptr;                     //however stack is easier in pushing
		for (int i = 0; i < unit::GetAC() / 2; i++)
		{
			if (Gptr->GetAArmy().getAM().removeAlienMonster(enemy))
			{
				double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
				enemy->DecHealth(damage);
				ETshots++;
				if (!enemy->Wasattacked())
				{
					enemy->SetAttacked(true);
					enemy->SetTa(Gptr->GetTS());
				}
				if (enemy->GetHealth() < 0)
					Gptr->EnqueueKilled(enemy);
				else
					templist.push(enemy);
			}
			while (templist.pop(enemy))
				Gptr->GetAArmy().getAM().AddAlienMonster(enemy);
		}
		bool AttackAS = ((Gptr->GetEArmy().GetES().GetScount()) < (Gptr->GetAArmy().getAS().getCount() * 30 / 100)) ? true : false;
		if (AttackAS)
			ESbelow80 = true;
		if (!((Gptr->GetEArmy().GetES().GetScount()) >= (Gptr->GetAArmy().getAS().getCount() * 80 / 100)))
			if (ESbelow80)
			{
				LinkedQueue<unit*> templist;
				for (int i = unit::GetAC() / 2; i < unit::GetAC(); i++)
				{
					if (Gptr->GetAArmy().getAS().dequeue(enemy))
					{
						double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
						enemy->DecHealth(damage);
						ETshots++;
						if (!enemy->Wasattacked())
						{
							enemy->SetAttacked(true);
							enemy->SetTa(Gptr->GetTS());
						}
						if (enemy->GetHealth() < 0)
							Gptr->EnqueueKilled(enemy);
						else
							templist.enqueue(enemy);
					}
					while (templist.dequeue(enemy))
						Gptr->GetAArmy().getAS().enqueue(enemy);
				}
			}
		return ETshots;
	}
};