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
			GetattackedIDs().enqueue(enemy->GetId());
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

void ESoldier::PrintAttacked()
{
	if (!GetattackedIDs().isEmpty())
	{
		int id;
		cout << "ES " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(id))
		{
			cout << id;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Alien units shot by ES" << GetId() << endl;
	}
}