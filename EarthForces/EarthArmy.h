#pragma once
#ifndef EArmy
#define EArmr
#include"LinkedListStack.h"
#include"LinkedQueue.h"
#include"../unit.h";
#include"EarthSoldiers.h"
#include"EarthTank.h"
#include"EarthGunnery.h"
//#include"..\Game\Game.h"
class Game;
class EarthArmy
{
	Game* Gptr;
	LinkedQueue<unit*> ESoldiers;
	LinkedListStack<unit*> ETanks;
	LinkedQueue<unit*> EGunnery;
	int Scount;
	int Tcount;
	int Gcount;
	int id;
public:
	EarthArmy(Game* g=nullptr);
	bool EnqueueESoldier(unit* s);
	bool EnqueueETank(unit* t);
	bool EnqueueEGunnery(unit* g);
	LinkedQueue<unit*> GetESoldiers();
	LinkedListStack<unit*> GetETanks();
	LinkedQueue<unit*> GetEGunnery();
	void PrintArmy();
};
#endif
