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
	bool Infect(int z);
	int GetScount();
	int GetInfCount();
	LinkedQueue<unit*> GetInfected();
	void PrintES();
	~EarthSoldiers();
};
#endif
