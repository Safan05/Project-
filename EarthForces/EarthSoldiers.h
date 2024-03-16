#ifndef EarthS
#define EarthS
#include"../unit.h";
class Game;
class EarthSoldiers:public unit
{
	
public:
	EarthSoldiers(int H, int P, int AC, int T);
	bool attack(Game* GPtr);
};
#endif
