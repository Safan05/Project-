#include "ASoldier.h"
#include"ESoldier.h"

ASoldier::ASoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ASoldier::attack(Game* const & GPtr)
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
			if (damage / enemy->GetHealth() >= 0.08 && damage < enemy->GetHealth())
			{
				ESoldier* es = dynamic_cast<ESoldier*> (enemy);
				es->setUmlJoinTime(GPtr->GetTS());
				GPtr->GetEArmy().GetUL().AddUnit(enemy);
			}
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!enemy->Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();
				enemy->SetAttacked(true);
				enemy->SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - *(enemy->GetImpTime()));

			}
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			else temp.enqueue(enemy);
		}
	}
	while (temp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);
	return flag;
}

void ASoldier::PrintAttacked()
{
	int i;
	if (GetattackedIDs().peek(i))
	{
		cout << "AS " << GetId() << " shots [";
		while (GetattackedIDs().dequeue(i))
		{
			cout << i;
			if (!GetattackedIDs().isEmpty())
				cout << ", ";
		}
		cout << "] IDs of all Earth units shot by AS" << GetId() << endl;
	}
}