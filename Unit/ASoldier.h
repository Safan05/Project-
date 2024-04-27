#pragma once
#include"../Unit/unit.h"
#include"../Game/Game.h"
#include<iostream>
using namespace std;

class ASoldier : public unit
{		
public:
	ASoldier(double H, int P, int AC, int T);
	bool attack(Game* const & GPtr);
	void PrintAttacked();
};