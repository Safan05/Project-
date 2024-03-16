#ifndef EArmy
#define EArmr
#include"LinkedListStack.h"
#include"LinkedQueue.h"
#include"../unit.h";
#include"EarthSoldiers.h"
#include"EarthTank.h"
#include"EarthGunnery.h"
class EarthArmy
{
	LinkedQueue<EarthSoldiers> ESoldiers;
	LinkedListStack<EarthTank> ETanks;
	LinkedQueue<EarthGunnery> EGunnery;
	int Scount;
	int Tcount;
	int Gcount;
	//Game* Gptr;
public:
	EarthArmy();
	bool EnqueueESoldier(const EarthSoldiers& s);
	bool EnqueueETank(const EarthTank& t);
	bool EnqueueEGunnery(const EarthGunnery& g);

};
#endif
