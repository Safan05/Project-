#pragma once
#include"..\unit.h"
#include"..\LinkedQueue.h"
class AlienDrones :public unit, public LinkedQueue<unit*>
{
	int count;
public:
	AlienDrones(double h = 0, int p = 0, int ac = 0, int t = 0);
	bool enqueue(unit* s);
	bool deque(unit*, unit*);
	void PrintAD();
	int getCount();
	bool attack(Game* GPtr);
};