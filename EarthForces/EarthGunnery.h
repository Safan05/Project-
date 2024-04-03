#ifndef EarthG
#define EarthG
#include"../unit.h"
class Game;
class EarthGunnery :public priQueue<unit*>
{
	int Gcount;
	int EGshots;
public:
	EarthGunnery();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	bool attack(Game* GPtr);
	int GetGcount();
	void PrintEG();
};
#endif
