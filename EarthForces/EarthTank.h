#ifndef EarthT
#define EarthT
#include"LinkedListStack.h"
#include"../unit.h";
class EarthTank
{
	LinkedListStack<unit> ETanks;
	int Tcount;
public:
	EarthTank();
	bool EnqueueETank(const unit& t);

};
#endif
