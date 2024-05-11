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
			double damage = (this->GetPow() * this->GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!enemy->Wasattacked())
			{
				Gptr->GetAArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(Gptr->GetTS());
				Gptr->SetADf(Gptr->GetTS() - enemy->GetJoin());
			}
			if (enemy->is_killed())
			{
				enemy->SetTd(Gptr->GetTS());
				Gptr->AddKilled(enemy);
			}
			else
				templist.enqueue(enemy);
		}
	}
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
