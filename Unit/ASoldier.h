#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ASoldier : public unit
{
public:
	ASoldier(double H, int P, int AC, int T) :unit(H, P, AC, T)
	{
	}
	int attack(Game* GPtr)
	{
	//	if (!frontPtr || GPtr->GetEArmy().GetES().isEmpty())
	//		return false;
	//	unit* enemy = NULL;
	//	unit* attacker = frontPtr->getItem();
	//	LinkedQueue<unit*> temp;
	//	for (int i = 0; i < attacker->GetAC(); i++)
	//	{
	//		if (GPtr->GetEArmy().GetES().dequeue(enemy))
	//		{
	//			double damage = (attacker->GetPow() * attacker->GetHealth() / 100) / sqrt(enemy->GetHealth());
	//			enemy->SetAttacked(true);
	//			enemy->DecHealth(damage);
	//			if (enemy->is_killed())
	//				GPtr->EnqueueKilled(enemy);
	//			else temp.enqueue(enemy);
	//		}
	//	}
	//	while (temp.dequeue(enemy))
	//		GPtr->GetEArmy().GetES().enqueue(enemy);
	//	return true;
		return 0;
	}

};