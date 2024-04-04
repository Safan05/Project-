#pragma once
#include"..\DS\DoubleQueue.h"
class unit;
class Game;
class AlienDrones :public unit, public DoubleQueue<unit*>
{
	int count;
public:
	AlienDrones(double h = 0, int p = 0, int ac = 0, int t = 0);
	bool enqueue(unit*& front, unit*& back);
	bool dequeue(unit*&, unit*&);
	void PrintAD();
	int getCount();
	int attack(Game* GPtr);
};