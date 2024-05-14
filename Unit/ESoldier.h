#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
class ESoldier : public unit
{
	bool Infected;
	bool AttackedWhileInfected;
	bool immune;
	int UmlJoinTime;
public:
	ESoldier(double H, int P, int AC, int T);
	bool attack(Game* const & GPtr);
	void SetInfected(bool v);
	bool IsInfected();
	void setImuune(bool im);
	bool isImmune();
	void PrintAttacked();
	void setAWI(bool t);
	bool getAWI();
	void setUmlJoinTime(int);
	int getUmlJoinTime();
};