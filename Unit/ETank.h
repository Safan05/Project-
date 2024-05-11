#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ETank :public unit
{
	bool ESbelow80;
	int UmlJoinTime;
public:
	ETank(double H, int P, int AC, int T);
	bool attack(Game* const & Gptr);
	void PrintAttacked();
	void setUmlJoinTime(int);
	int getUmlJoinTime();
};