#include "EarthSoldiers.h"

EarthSoldiers::EarthSoldiers(int H, int P, int AC, int T) :unit(H, P, AC, T)
{
}


bool EarthSoldiers::attack()
{
	return false;
}

bool EarthSoldiers::AddtoKilled(const unit* u)
{
	return false;
}
