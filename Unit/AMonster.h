#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class AMonster : public unit
{
public:
	AMonster(double H, int P, int AC, int T) :unit(H, P, AC, T)
	{
	}
	bool attack(Game* GPtr)
	{
	//	if (count == 0 || (GPtr->GetEArmy().GetET().isEmpty() && GPtr->GetEArmy().GetES().isEmpty()))
	//		return false;
	//	LinkedListStack<unit*> Ttemp;
	//	LinkedQueue<unit*> Stemp;
	//	unit* attacker = monsters[rand() % count];
	//	unit* enemy = NULL;
	//	int ac = attacker->GetAC();

	//	//Attacking tanks with half attack capacity
	//	for (int i = 0; i < ac / 2; i++)
	//	{
	//		if (GPtr->GetEArmy().GetET().pop(enemy))
	//		{
	//			double damage = (attacker->GetPow() * attacker->GetHealth() / 100) / sqrt(enemy->GetHealth());
	//			enemy->SetAttacked(true);
	//			enemy->DecHealth(damage);
	//			if (enemy->is_killed())
	//				GPtr->EnqueueKilled(enemy);
	//			else Ttemp.push(enemy);
	//		}
	//	}
	//	while (Ttemp.pop(enemy))
	//		GPtr->GetEArmy().GetET().push(enemy);

	//	//Attacking soldiers with half attack capacity
	//	for (int i = ac / 2; i < ac; i++)
	//	{
	//		if (GPtr->GetEArmy().GetES().dequeue(enemy))
	//		{
	//			double damage = (attacker->GetPow() * attacker->GetHealth() / 100) / sqrt(enemy->GetHealth());
	//			enemy->SetAttacked(true);
	//			enemy->DecHealth(damage);
	//			if (enemy->is_killed())
	//				GPtr->EnqueueKilled(enemy);
	//			else Stemp.enqueue(enemy);
	//		}
	//	}
	//	while (Stemp.dequeue(enemy))
	//		GPtr->GetEArmy().GetES().enqueue(enemy);

	//	return true;
		return 0;
	}
};