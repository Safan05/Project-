#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ADrone : public unit
{
public:
	ADrone(double H, int P, int AC, int T);
	bool attack(Game* const & GPtr);
	void PrintAttacked();
};