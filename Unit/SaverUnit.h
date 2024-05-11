#pragma once
#include"unit.h"
#include"ESoldier.h"
#include"..\Game\Game.h"
class SaverUnit :public unit
{
public:
	SaverUnit(double H, int P, int AC, int T);
	bool attack(Game* const& Gptr);
	void PrintAttacked();
};
