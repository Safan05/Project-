#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ESoldier : public unit
{
public:
	ESoldier(double H, int P, int AC, int T);
	bool attack(Game* GPtr);
	
};