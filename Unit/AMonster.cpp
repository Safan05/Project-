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
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			enemy->SetTa(GPtr->GetTS());
			attacked_IDs.enqueue(enemy->GetId());
			if (enemy->is_killed())
				GPtr->EnqueueKilled(enemy);
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
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			enemy->SetTa(GPtr->GetTS());
			attacked_IDs.enqueue(enemy->GetId());
			if (enemy->is_killed())
				GPtr->EnqueueKilled(enemy);
			else Stemp.enqueue(enemy);
		}
	}
	while (Stemp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);

	return flag;
}

void AMonster::printShots()
{
	cout << "AS " << GetId() << " shots [";
	int i;
	while (attacked_IDs.dequeue(i))
		cout << i << " ";
	cout << "]\n";
}
