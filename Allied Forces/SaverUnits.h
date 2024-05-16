#pragma once
#include"..\DS\LinkedQueue.h"
class Game;
class unit;
class SaverUnits :public LinkedQueue<unit*>
{
	int count;
public:
	SaverUnits();
	bool enqueue(unit*&);      //same as in the LinkedQueue class + increasing the count 
	bool dequeue(unit*&);      //same as in the LinkedQueue class + decreasing the count
	int Getcount();
	void PrintSU();
	~SaverUnits();
};
