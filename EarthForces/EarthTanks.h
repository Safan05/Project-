#ifndef EarthT
#define EarthT
#include"../DS/LinkedStack.h"
class unit;
class Game;
class EarthTanks :public LinkedListStack<unit*>
{
	int Tcount;
	bool ESbelow80;
public:
	EarthTanks();
	bool push(unit*&);
	bool pop(unit*&);
	int GetTcount();
	void PrintET();
	~EarthTanks();
};
#endif
