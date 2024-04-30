#pragma once
#ifndef HealU
#define HealU
#include"../DS/LinkedStack.h"
class unit;
class Game;
class HealUnits :public LinkedListStack<unit*>
{
	int HUCount;
public:
	HealUnits();
	bool push(unit*&);
	bool pop(unit*&);
	int GetHUcount();
	void PrintHU();
	~HealUnits();
};
#endif

