#include "AMonster.h"

AMonster::AMonster(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool AMonster::attack(Game* const & GPtr)
{
	bool flag = false;
	LinkedListStack<unit*> Ttemp;
	LinkedQueue<unit*> Stemp;
	unit* enemy = NULL;

	//Attacking tanks with half attack capacity
	for (int i = 0; i < GetAC() / 2; i++)
	{
		if (GPtr->GetEArmy().GetET().pop(enemy))
		{
			flag = true;
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();
				SetAttacked(true);
				SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());
			}
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			else Ttemp.push(enemy);
		}
	}
	while (Ttemp.pop(enemy))
		GPtr->GetEArmy().GetET().push(enemy);

	//Attacking soldiers with half attack capacity
	for (int i = GetAC() / 2; i < GetAC(); i++)
	{
		if (GPtr->GetEArmy().GetES().dequeue(enemy))
		{
			flag = true;
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			//enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();
				SetAttacked(true);
				SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - enemy->GetJoin());
			}
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			else Stemp.enqueue(enemy);
		}
	}
	while (Stemp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);

	return flag;
}

void AMonster::PrintAttacked()
{
	cout << "AM " << GetId() << " shots [";
	int i;
	while (GetattackedIDs().dequeue(i))
	{
		cout << i;
		if (!GetattackedIDs().isEmpty())
			cout << ", ";
	}
	cout << "] IDs of all Earth units shot by AM" << GetId() << endl;
}