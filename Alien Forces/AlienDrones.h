#pragma once
#include"..\DS\DoubleQueue.h"
class unit;
class Game;
class AlienDrones :public DoubleQueue<unit*>
{
	int count;
public:
	AlienDrones();
	bool enqueue(unit*& front, unit*& back);
	bool dequeue(unit*&, unit*&);
	void PrintAD();
	int getCount();
	bool ADattack(Game* const& GPtr);
	~AlienDrones();
};