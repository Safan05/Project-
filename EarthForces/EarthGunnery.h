#ifndef EarthG
#define EarthG
#include"../unit.h";
class EarthGunnery:public unit
{
	
public:
	EarthGunnery(double H, int P, int AC, int T);
	bool attack(Game* GPtr);
};
#endif
