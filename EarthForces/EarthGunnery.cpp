#include"EarthGunnery.h"

EarthGunnery::EarthGunnery(double H, int P, int AC, int T) :unit(H, P, AC, T)
{
}

bool EarthGunnery::attack(Game* ptr)
{
    return false;
}
