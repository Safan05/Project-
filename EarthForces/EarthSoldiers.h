#ifndef EarthS
#define EarthS
#include"../unit.h"
#include"../DS/LinkedQueue.h"
class Game;
class EarthSoldiers:public LinkedQueue<unit*>
{
	int Scount;
	int ESshots;
public:
	EarthSoldiers();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	int GetScount();
	int GetESshots();
	bool ESattack(Game* GPtr);
	void PrintES();
};
#endif
