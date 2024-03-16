#include "EarthTank.h"
EarthTank::EarthTank(double H, int P, int AC, int T) : unit(H, P, AC, T)
{
}

bool EarthTank::attack(Game* ptr)
{
	return false;
}
