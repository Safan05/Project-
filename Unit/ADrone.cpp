#include "ADrone.h"

ADrone::ADrone(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool ADrone::attack(Game* const & GPtr)
{
	bool flag = false;
	int j;
	LinkedListStack<unit*> Ttemp;
	priQueue<unit*> Gtemp;
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
				GPtr->SetEDf(GPtr->GetTS() - *(enemy->GetImpTime()));
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

	//Attacking Gunnery with half attack capacity
	for (int i = GetAC() / 2; i < GetAC(); i++)
	{
		if (GPtr->GetEArmy().GetEG().dequeue(enemy))
		{
			flag = true;
			double damage = (GetPow() * GetHealth() / 100) / sqrt(enemy->GetHealth());
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			GetattackedIDs().enqueue(enemy->GetId());
			if (!Wasattacked())
			{
				GPtr->GetEArmy().IncAttackCount();
				SetAttacked(true);
				SetTa(GPtr->GetTS());
				GPtr->SetEDf(GPtr->GetTS() - *(enemy->GetImpTime()));
			}
			if (enemy->is_killed())
			{
				enemy->SetTd(GPtr->GetTS());
				GPtr->AddKilled(enemy);
			}
			else Gtemp.enqueue(enemy, enemy->GetPow() + enemy->GetHealth());
		}
	}
	while (Gtemp.dequeue(enemy,j))
		GPtr->GetEArmy().GetES().enqueue(enemy);

	return flag;
}

void ADrone::PrintAttacked()
{
	cout << "AD " << GetId() << " shots [";
	int i;
	while (GetattackedIDs().dequeue(i))
	{
		cout << i;
		if (!GetattackedIDs().isEmpty())
			cout << ", ";
	}
	cout << "] IDs of all Earth units shot by AD" << GetId() << endl;
}
