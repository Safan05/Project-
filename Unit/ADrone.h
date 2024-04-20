#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ADrone : public unit
{
public:
	ADrone(double H, int P, int AC, int T) :unit(H, P, AC, T)
	{
	}
	bool attack(Game* GPtr)
		{
		//	if (count < 2 || (GPtr->GetEArmy().GetET().isEmpty() && GPtr->GetEArmy().GetEG().isEmpty()))
		//		return false;
		//	unit* enemy;
		//	unit* attacker1 = frontPtr->getItem(), * attacker2 = backPtr->getItem();
		//	//to be contninued after better understanding of the logic
		return 0;

		}
};