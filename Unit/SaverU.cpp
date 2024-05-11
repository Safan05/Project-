#include "SaverU.h"

SaverU::SaverU(double H, int P, int AC, int T) : unit(H, P, AC, T)
{
}

bool SaverU::attack(Game* const& Gptr)
{
	return false;
}

void SaverU::PrintAttacked()
{

}
