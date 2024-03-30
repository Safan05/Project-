#ifndef EarthT
#define EarthT
#include"../unit.h";
#include"../DS/LinkedStack.h"
class EarthTank :public LinkedListStack<unit*>, public unit
{
	int Tcount;
public:
	EarthTank(double H = 0, int P = 0, int AC = 0, int T = 0);
	bool Push(unit*);
	bool Pop(unit*&);
	bool attack(Game* GPtr);
	int GetTcount();
	void PrintET();
};
#endif
