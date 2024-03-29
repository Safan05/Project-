#ifndef EarthG
#define EarthG
#include"../unit.h";
#include"../DS/priQueue.h"
class EarthGunnery :public priQueue<unit*>, public unit
{
	int Gcount;
public:
	EarthGunnery(double H = 0, int P = 0, int AC = 0, int T = 0);
	bool Enqueue(unit*);
	bool Dequeue(unit*);
	bool attack(Game* GPtr);
	int GetGcount();
	void PrintEG();
};
#endif
