#ifndef EarthS
#define EarthS
#include"../DS/LinkedQueue.h"
class Game;
class unit;
class EarthSoldiers :public LinkedQueue<unit*>
{
	int Scount;
	int InfCount;
	LinkedQueue<unit*> InfectedES;
public:
	EarthSoldiers();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	bool InfEnqueue(unit*&);
	bool InfDequeue(unit*&);
	int GetScount();
	void PrintES();
	~EarthSoldiers();
};
#endif
