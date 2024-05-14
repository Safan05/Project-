#pragma once
#include "unit.h"
#include "../Game/Game.h"
class HUnit:public unit
{
	static LinkedQueue<int> Healed_Ids;
public:
	HUnit(double H, int P, int AC, int T);
	bool attack(Game* const& Gptr);
	void PrintAttacked();
};

