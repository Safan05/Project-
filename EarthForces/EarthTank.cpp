#include "EarthTank.h"

EarthTank::EarthTank()
{
	Tcount = 0;
}

bool EarthTank::EnqueueETank(const unit& t)
{
	return ETanks.push(t);
}
