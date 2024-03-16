#include "EarthArmy.h"

EarthArmy::EarthArmy()
{
	Scount = 0;
	Tcount = 0;
	Gcount = 0;
}

bool EarthArmy::EnqueueESoldier(const EarthSoldiers& s)
{
	Scount++;
	return ESoldiers.enqueue(s);
}

bool EarthArmy::EnqueueETank(const EarthTank& t)
{
	Tcount++;
	return ETanks.push(t);
}

bool EarthArmy::EnqueueEGunnery(const EarthGunnery& g)
{
	Gcount++;
	return EGunnery.PriorEnqueue(g);
}
