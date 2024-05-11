#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ETank :public unit
{
	bool ESbelow80;
public:
	ETank(double H, int P, int AC, int T);
	bool attack(Game* const & Gptr);
	void PrintAttacked();
};