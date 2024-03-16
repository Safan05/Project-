#ifndef EarthT
#define EarthT
#include"../unit.h";
class EarthTank:public unit
{

public:
	EarthTank(int H, int P, int AC, int T);
	bool attack();
};
#endif
