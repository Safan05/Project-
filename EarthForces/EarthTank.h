#ifndef EarthT
#define EarthT
#include"../unit.h";
class EarthTank:public unit
{

public:
	EarthTank(double H, int P, int AC, int T);
	bool attack(Game* GPtr);
};
#endif
