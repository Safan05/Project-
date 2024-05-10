#include "ASoldier.h"

ASoldier::ASoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ASoldier::attack(Game* const& GPtr)
{
	bool flag = false;
	unit* enemy = NULL;
	LinkedQueue<unit*> temp;
	for (int i = 0; i < GetAC(); i++)
	{
		if (GPtr->GetEArmy().GetES().dequeue(enemy))
		{
			flag = true;
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!Wasattacked())
			{
				SetAttacked(true);
				SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - *(enemy->GetImpTime()));
				if (enemy->is_killed())
				{
					enemy->SetTd(GPtr->GetTS());
					GPtr->GetKList().AddKilled(enemy);
				}
				else if (enemy->GetHPercent() <= 20)
					GPtr->GetEArmy().GetUL().AddUnit(enemy);

				else temp.enqueue(enemy);
			}
		}
		while (temp.dequeue(enemy))
			GPtr->GetEArmy().GetES().enqueue(enemy);
		return flag;
	}
}

void ASoldier::PrintAttacked()
{
	cout << "AS " << GetId() << " shots [";
	int i;
	while (GetattackedIDs().dequeue(i))
	{
		cout << i;
		if (!GetattackedIDs().isEmpty())
			cout << ", ";
	}
	cout << "] IDs of all Earth units shot by AS" << GetId() << endl;
}
