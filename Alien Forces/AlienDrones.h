#pragma once
#include"..\DS\DoubleQueue.h"
class unit;
class Game;
class AlienDrones :public DoubleQueue<unit*>
{
	int count;
	int shots;
public:
	AlienDrones();
	bool enqueue(unit*& front, unit*& back);
	bool dequeue(unit*&, unit*&);
	void PrintAD();
	int getCount();
};