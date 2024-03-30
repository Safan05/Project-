#pragma once
#include"..\unit.h"
#include"..\DS\LinkedQueue.h"

class AlienSoldiers :public unit, public LinkedQueue<unit*>
{
	int count;
public:
	AlienSoldiers(double h = 0, int p = 0, int ac = 0, int t = 0);
	bool enqueue(unit* s);
	bool dequeue(unit* s);
	void PrintAS();
	int getCount();
	bool attack(Game* GPtr);
};