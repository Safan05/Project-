#pragma once
#include"..\DS\LinkedQueue.h"
class unit;
class Game;
class AlienSoldiers :public LinkedQueue<unit*>
{
	int count;
public:
	AlienSoldiers();
	bool enqueue(unit*& s);    //same as in the LinkedQueue class + increasing the count 
	bool dequeue(unit*& s);    //same as in the LinkedQueue class + decreasing the count
	void PrintAS();
	int getCount();
	~AlienSoldiers();
};