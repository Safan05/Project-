#pragma once
#include"unit.h" 
class SaverU:public unit
{
public:
	SaverU(double H, int P, int AC, int T);
	bool attack(Game* const& Gptr);
	void PrintAttacked();
};

