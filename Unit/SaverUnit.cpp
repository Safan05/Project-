#include "SaverUnit.h"

SaverUnit::SaverUnit(double H, int P, int AC, int T) :unit(H, P, AC, T) {}

bool SaverUnit::attack(Game* const& Gptr)
{
	return true;
}

void SaverUnit::PrintAttacked(){}
