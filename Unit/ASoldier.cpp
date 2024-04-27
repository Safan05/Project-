#include "ASoldier.h"

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
			enemy->SetAttacked(true);
			enemy->DecHealth(damage);
			enemy->SetTa(GPtr->GetTS());
			GetattackedIDs().enqueue(enemy->GetId());
			if (enemy->is_killed())
				GPtr->EnqueueKilled(enemy);
			else temp.enqueue(enemy);
		}
	}
	while (temp.dequeue(enemy))
		GPtr->GetEArmy().GetES().enqueue(enemy);
	return flag;
}

void ASoldier::printShots()
{
	cout << "AS " << GetId() << " shots [";
	int i;
	while (GetattackedIDs().dequeue(i))
		cout << i << " ";
	cout << "]\n";
}
