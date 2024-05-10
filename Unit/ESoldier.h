#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ESoldier : public unit
{
	bool Infected;
public:
	ESoldier(double H, int P, int AC, int T);
	bool attack(Game* const & GPtr);
	void SetInfected(bool v);
	bool IsInfected();
	void SpreadInfection(Game* const& GPtr);
	void PrintAttacked();
};