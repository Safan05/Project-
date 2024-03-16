#ifndef EarthS
#define EarthS
#include"../unit.h";
#include"LinkedQueue.h"
//#include"..\Game\Game.h"
class Game;
class EarthSoldiers:public unit
{
	
public:
	EarthSoldiers(double H, int P, int AC, int T);
	bool attack(Game* GPtr);
};
#endif
