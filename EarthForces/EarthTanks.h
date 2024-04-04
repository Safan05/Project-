#ifndef EarthT
#define EarthT
#include"../DS/LinkedStack.h"
class unit;
class Game;
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
	~EarthTanks();
};
#endif
