#ifndef EarthS
#define EarthS
#include"../DS/LinkedQueue.h"
class Game;
class unit;
class EarthSoldiers :public LinkedQueue<unit*>
{
	int Scount;
	int InfCount;
	unit* InfectedES;     //Infected front in queue 
public:
	EarthSoldiers();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	void SpreadInfection();
	int GetScount();
	int GetInfCount();
	unit*& GetInfected();
	void PrintES();
	~EarthSoldiers();
};
#endif
