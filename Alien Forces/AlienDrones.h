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
	bool peek(unit*&, unit*&);
	void PrintAD();
	int getCount();
	~AlienDrones();
};