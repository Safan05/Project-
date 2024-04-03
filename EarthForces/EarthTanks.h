#ifndef EarthT
#define EarthT
#include"../unit.h";
#include"../EarthForces/ETank.h"
class EarthTanks :public LinkedListStack<unit*>
{
	int Tcount;
	int ETshots;
	bool ESbelow80;
public:
	EarthTanks();
	bool push(unit*&);
	bool pop(unit*&);
	bool ETattack(Game* GPtr);
	int GetTcount();
	void PrintET();
};
#endif
