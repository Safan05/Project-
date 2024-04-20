#ifndef EarthG
#define EarthG
#include"../DS/priQueue.h"
class unit;
class Game;
class EarthGunnery :public priQueue<unit*>
{
	int Gcount;
public:
	EarthGunnery();
	bool enqueue(unit*&);
	bool dequeue(unit*&);
	int GetGcount();
	void PrintEG();
	~EarthGunnery();
};
#endif
