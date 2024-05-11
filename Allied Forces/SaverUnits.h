#pragma once
#include"..\DS\LinkedQueue.h"
class Game;
class unit;
class SaverUnits :public LinkedQueue<unit*>
{
	int count;
public:
	SaverUnits();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	int Getcount();
	void PrintSU();
	~SaverUnits();
};
