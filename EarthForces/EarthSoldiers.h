#ifndef EarthS
#define EarthS
#include"../DS/LinkedQueue.h"
class Game;
class unit;
class EarthSoldiers :public LinkedQueue<unit*>
{
	int Scount;
public:
	EarthSoldiers();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	int GetScount();
	void PrintES();
	~EarthSoldiers();
};
#endif
