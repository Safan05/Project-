#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class AMonster : public unit
{
public:
	AMonster(double H, int P, int AC, int T);
	bool attack(Game* const & GPtr);
	void printShots();
};