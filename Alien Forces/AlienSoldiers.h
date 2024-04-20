#pragma once
#include"..\DS\LinkedQueue.h"
class unit;
class Game;
class AlienSoldiers :public LinkedQueue<unit*>
{
	int count;
public:
	AlienSoldiers();
	bool enqueue(unit*& s);
	bool dequeue(unit*& s);
	void PrintAS();
	int getCount();
	bool ASattack(Game* GPtr);
	~AlienSoldiers();
};