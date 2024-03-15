#include "EarthSoldiers.h"

EarthSoldiers::EarthSoldiers(int H, int P, int AC, int T) :unit(H, P, AC, T)
{
	Scount = 0;
}

bool EarthSoldiers::EnqueueESoldier(const unit& s)
{
	return ESoldiers.enqueue(s);
}

bool EarthSoldiers::attack()
{
	return false;
}

bool EarthSoldiers::AddtoKilled(const unit& u)
{
	return false;
}
