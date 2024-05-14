#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class AMonster : public unit
{
	LinkedQueue<int> infectedList;
public:
	AMonster(double H, int P, int AC, int T);
	bool attack(Game* const & GPtr);
	void PrintAttacked();
	void PrintInfected();
};