#ifndef EarthS
#define EarthS
#include"../unit.h";
#include"../DS/LinkedQueue.h"
class Game;
class EarthSoldiers:public LinkedQueue<unit*>,public unit
{
	int Scount;
public:
	EarthSoldiers(double H = 0, int P = 0, int AC = 0, int T = 0);
	bool enqueue(unit*);
	bool dequeue(unit*);
	int GetScount();
	bool attack(Game* GPtr);
	void PrintES();
};
#endif
