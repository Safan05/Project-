#include "SaverU.h"
#include"ESoldier.h"

SaverU::SaverU(double H, int P, int AC, int T) : unit(H, P, AC, T)
{
}

bool SaverU::attack(Game* const& Gptr)
{
	LinkedQueue<unit*> templist;
	unit* enemy = nullptr;
	for (int i = 0; i < unit::GetAC(); i++)
	{
		if (Gptr->GetAArmy().getAS().dequeue(enemy))
		{
			//calculate the damage and decrement enemy's health
			double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			//add enemy's ID to the attacked list
			GetattackedIDs().enqueue(enemy->GetId());
			//set the output file parameters
			if (!enemy->Wasattacked())
			{
				Gptr->GetAArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(Gptr->GetTS());
				Gptr->SetADf(Gptr->GetTS() - enemy->GetJoin());
			}
			//if enemy's health reaches 0, add it to killed list 
			if (enemy->is_killed())
			{
				enemy->SetTd(Gptr->GetTS());
				Gptr->AddKilled(enemy);
			}
			//if enemy is still alive, add it to temp list 
			else
				templist.enqueue(enemy);
		}
	}
	//return all units in temp list to their original list
	while (templist.dequeue(enemy))
		Gptr->GetAArmy().getAS().enqueue(enemy);
	return true;
}

void SaverU::PrintAttacked()
{
	if (!GetattackedIDs().isEmpty())
	{
		int id;
		cout << "SU " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(id))
		{
			cout << id;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Alien units shot by ES" << GetId() << endl;
	}
}
